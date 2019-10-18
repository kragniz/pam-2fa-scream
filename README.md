pam-2fa-scream
==============

Highly secure second factor auth by screaming at your computer.

    meson build
    ninja -C build

    cp build/meson-out/libpam_2fa_scream.so /lib/security/pam_scream.so
    chmod 755 /lib/security/pam_scream.so

Edit something in `/etc/pam.d/` and add

    auth            required        pam_scream.so
