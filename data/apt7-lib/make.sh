cp -a "$(PKG_DEST_ _apt7)"/etc "${PKG_DEST}"
cp -a "$(PKG_DEST_ _apt7)"/var "${PKG_DEST}"

pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _apt7)"/usr/lib "${PKG_DEST}"/usr
pkg: rm -f /usr/lib/apt/methods/https
pkg: ln -s http /usr/lib/apt/methods/https
