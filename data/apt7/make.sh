pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _apt7)"/usr/bin "${PKG_DEST}"/usr
cp -a "$(PKG_DEST_ _apt7)"/usr/include "${PKG_DEST}"/usr
pkg: rm -f /usr/bin/apt-key
