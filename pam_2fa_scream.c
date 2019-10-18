#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <alsa/asoundlib.h>

static float get_loudyness(void) {
    float result = 0.0f;
    snd_pcm_t *waveform;

    if (snd_pcm_open(&waveform, "default", SND_PCM_STREAM_CAPTURE, 0) != 0)
        return 0;

    if (!snd_pcm_set_params(waveform, SND_PCM_FORMAT_S16_LE,
                            SND_PCM_ACCESS_RW_INTERLEAVED, 2, 48000, 1, 0)) {
        short buffer[256];
        if (snd_pcm_readi(waveform, buffer, 128) == 128) {
            for (int i = 0; i < 256; ++i) {
                float s = buffer[i] / 32768.0f;
                if (s < 0) {
                    s *= -1;
                }
                if (result < s) {
                    result = s;
                }
            }
        }
    }

    snd_pcm_close(waveform);
    return result;
}

static bool check_for_big_loud(float big_loud_limit) {
    bool is_big_loud = false;
    float loudest = 0;

    for (size_t i = 0; i < 100; i++) {
        float loud = get_loudyness();
        if (loud > loudest) {
            loudest = loud;
        }
        if (loud > big_loud_limit) {
            is_big_loud = true;
            break;
        }
        usleep(10000);
    }

    if (!is_big_loud) {
        printf("Auth failed: you must scream at the computer (%.0f%% required, "
               "only recieved %.0f%%)\n",
               big_loud_limit * 100, loudest * 100);
    }
    return is_big_loud;
}

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc,
                        const char **argv) {
    if (check_for_big_loud(0.3)) {
        return PAM_SUCCESS;
    } else {
        return PAM_AUTH_ERR;
    }
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return PAM_IGNORE;
}
