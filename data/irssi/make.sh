pkg:setup
pkg:autoconf
pkg:configure --enable-static LD="${PKG_TARG}-ld"
make -j8
pkg:install
