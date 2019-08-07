pkg:setup
pkg:configure --with-ogg="$(PKG_DEST_ ogg)"
make -j8
pkg:install
