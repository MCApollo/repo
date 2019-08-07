pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _libxvidcore4)"/usr/lib "${PKG_DEST}"/usr/
pkg: rm /usr/lib/libxvidcore.dylib
