pkg:setup
cd src
patch -p1 <../../*.patch
autoconf
pkg:configure --prefix="${PKG_DEST}/usr" sr_cv_next=no sr_cv_sprintf_int=yes sr_cv_sprintf_declare=no sr_cv_unix_sockets=yes sr_cv_gethostid=yes
make
pkg: mkdir -p /usr/man/man1 /usr/bin
pkg:install
