pkg:setup
touch aclocal.m4
autoconf
# XXX: fix libgnutls-config call to add --prefix
libgnutls_config_args="--prefix=$(PKG_DEST_ gnutls)/usr" pkg:configure --with-libiconv-prefix="${PKG_ROOT}" --with-libgnutls-prefix="$(PKG_DEST_ gnutls)/usr" --disable-python --disable-ruby
make
pkg:install
