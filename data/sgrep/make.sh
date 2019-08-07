pkg:setup
autoreconf -f -i
pkg:configure
make CC="${PKG_TARG}"-gcc -j8
pkg:install
