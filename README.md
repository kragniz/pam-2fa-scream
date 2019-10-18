
    meson build
    ninja -C build

    cp build/meson-out/libpam_2fa_scream.so /lib/security/pam_scream.so
    chmod 755 /lib/security/pam_scream.so
