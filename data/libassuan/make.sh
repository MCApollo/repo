pkg:setup
autoreconf -fi
pkg:configure --with-pth-prefix="$(PKG_DEST_ npth)/usr" --with-gpg-error-prefix="$(PKG_DEST_ libgpg-error)/usr"
make
pkg:install
