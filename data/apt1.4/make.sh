pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _apt1.4)"/usr/bin "${PKG_DEST}"/usr
pkg: rm -f /usr/bin/apt-key
