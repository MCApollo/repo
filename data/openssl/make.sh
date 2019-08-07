pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _openssl1.0)"/etc "${PKG_DEST}"/
cp -a "$(PKG_DEST_ _openssl1.0)"/usr/bin "${PKG_DEST}"/usr
cp -a "$(PKG_DEST_ _openssl1.0)"/usr/lib/ssl "${PKG_DEST}"/usr/lib
