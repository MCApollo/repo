pkg:setup
make configure
pkg:configure ac_cv_c_c99_format=yes ac_cv_fread_reads_directories=no ac_cv_snprintf_returns_bogus=yes --without-tcltk CURL_CONFIG="$(PKG_DEST_ curl)/usr/bin/curl-config"
make -j8 NO_DARWIN_PORTS=1 NO_FINK=1
make -j8 install DESTDIR="${PKG_DEST}" NO_DARWIN_PORTS=1 NO_FINK=1 NO_INSTALL_HARDLINKS=yes
pkg: rm -f /usr/lib/perl/5.10.1/perllocal.pod
