pkg:setup
pkg:configure
pkg:make -j8
make install prefix="${PKG_DEST}/usr"
