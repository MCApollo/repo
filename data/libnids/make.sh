pkg:setup
pkg:configure --disable-libglib
make
make install install_prefix="${PKG_DEST}"
