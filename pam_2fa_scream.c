#include <stdio.h>

#include <security/pam_appl.h>
#include <security/pam_modules.h>

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc,
                        const char **argv) {
    puts("scream pam_sm_authenticate");
    return (PAM_IGNORE);
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    puts("scream pam_sm_setcred");
    return (PAM_IGNORE);
}

