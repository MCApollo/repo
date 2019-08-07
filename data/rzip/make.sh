pkg:setup
autoconf
pkg:configure
make
make install prefix="${PKG_DEST}/usr"
