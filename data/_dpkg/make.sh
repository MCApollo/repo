pkg:setup
pkg: cp %/macho.mgc .
pkg: cp %/sign.{c,h} lib/dpkg/
autoreconf
#autoconf
#cp -a libcompat/obstack.[ch] lib
pkg:configure --with-admindir=/var/lib/dpkg --disable-start-stop-daemon --disable-nls --sysconfdir=/etc --disable-linker-optimisations dpkg_cv_va_copy=yes --enable-static=yes --enable-shared=no --with-dpkg-deb-compressor=gzip --with-logdir=/var/log/dpkg TAR=tar PERL_LIBDIR="$("$(PKG_WORK_ perl)"/perl-5*/miniperl_top -e 'use Config; print $Config{vendorlib};')" PERL=/usr/bin/perl
pkg:make
pkg:install
