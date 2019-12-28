<p align="center">
  <img src="https://sr.ht/7AIA.png">
</p>

<h1 align="center">pam-2fa-scream</h1>


Highly secure second factor auth by screaming at your computer.

    [kgz@ayano ~]$ su
    Password: 
    Second factor: please scream loudly at your computer
    Authentication failed: you must scream louder (30% required, only received 9%)
    su: Authentication failure
    [kgz@ayano ~]$ su
    Password: 
    Second factor: please scream loudly at your computer
    [root@ayano kgz]# 

Building and installing
-----------------------

    meson build
    ninja -C build

    cp build/meson-out/libpam_2fa_scream.so /lib/security/pam_scream.so
    chmod 755 /lib/security/pam_scream.so

Edit something in `/etc/pam.d/` and add

    auth            required        pam_scream.so
