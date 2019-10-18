#define PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

#include <stdio.h>

#include <security/pam_appl.h>
#include <security/pam_modules.h>

int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc,
                        const char **argv) {
    puts("scream pam_sm_open_session");
    return (PAM_IGNORE);
}

int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc,
                         const char **argv) {
    puts("scream pam_sm_close_session");
    return (PAM_IGNORE);
}

int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc,
                     const char **argv) {
    puts("scream pam_sm_acct_mgmt");
    return (PAM_IGNORE);
}

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc,
                        const char **argv) {
    puts("scream pam_sm_authenticate");
    return (PAM_IGNORE);
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    puts("scream pam_sm_setcred");
    return (PAM_IGNORE);
}

int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc,
                     const char **argv) {
    puts("scream pam_sm_chauthtok");
    return (PAM_IGNORE);
}
