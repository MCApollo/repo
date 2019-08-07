pkg:setup
autoreconf -fiv
pkg:configure --with-libgcrypt-prefix="$(PKG_DEST_ gcrypt)/usr" --disable-static
make -j8
pkg:install
