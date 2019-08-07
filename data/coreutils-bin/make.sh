cp -a "$(PKG_DEST_ _coreutils)"/bin "${PKG_DEST}"
pkg: mkdir -p /usr/bin
cp -a "$(PKG_DEST_ _coreutils)"/usr/bin/dirname "${PKG_DEST}"/usr/bin
