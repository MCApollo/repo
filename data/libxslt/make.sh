pkg:setup
# XXX: fix libgcrypt-config call to add --prefix
libgcrypt_config_args="--prefix=$(PKG_DEST_ gcrypt)/usr" pkg:configure --with-python=no --with-libxml-prefix="$(PKG_DEST_ libxml2)/usr"
make
pkg:install
