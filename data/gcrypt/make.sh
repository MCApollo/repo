pkg:setup
pkg:configure --with-gpg-error-prefix="$(PKG_DEST_ libgpg-error)/usr"
make -j8
pkg:install
