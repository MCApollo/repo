pkg:setup
CFLAGS="-fcommon" pkg:configure --with-ksba-prefix="$(PKG_DEST_ libksba)/usr" --with-libassuan-prefix="$(PKG_DEST_ libassuan)/usr" --with-npth-prefix="$(PKG_DEST_ npth)/usr" --sysconfdir=/etc --with-gpg-error-prefix="$(PKG_DEST_ libgpg-error)/usr" --with-libgcrypt-prefix="$(PKG_DEST_ gcrypt)/usr"
make -j8
pkg:install
pkg: ln -s gnupg /usr/bin/gnupg2
