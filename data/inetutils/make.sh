pkg:setup
autoconf
# XXX: I miss talkd
pkg:configure ac_cv_type_sa_family_t=yes ac_cv_type_socklen_t=yes ac_cv_member_struct_utmp_ut_user=yes ac_cv_func_obstack=no --disable-ifconfig --disable-ping6 --disable-syslogd --disable-talkd --disable-traceroute --disable-whois ac_cv_header_utmp_h=no
make CFLAGS='-O2' -j8
pkg:install
pkg:bin ping
pkg: mkdir -p /sbin
ln -s /bin/ping "${PKG_DEST}"/usr/bin
ln -s /bin/ping "${PKG_DEST}"/sbin
