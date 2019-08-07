pkg:setup
make CC="${PKG_TARG}-gcc" LD="${PKG_TARG}-gcc" -j8
pkg: mkdir -p /usr/bin
pkg: cp -a pngcrush /usr/bin
