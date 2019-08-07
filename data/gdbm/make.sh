pkg:setup
pkg:configure
make
make install INSTALL_ROOT="${PKG_DEST}"
