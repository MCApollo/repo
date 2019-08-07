pkg:setup
pkg:configure
make -j8
make install prefix="${PKG_DEST}/usr"
pkg: ln -sf BitchX-1.2.1 /usr/bin/BitchX
