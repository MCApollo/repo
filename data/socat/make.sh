pkg:setup
pkg:configure --disable-tun ac_cv_ispeed_offset=9 sc_cv_sys_crdly_shift=12 sc_cv_sys_tabdly_shift=-1 sc_cv_sys_csize_shift=8 ac_cv_header_libutil_h=no
make CFLAGS="-O2 -D__APPLE_USE_RFC_3542"
pkg:install
