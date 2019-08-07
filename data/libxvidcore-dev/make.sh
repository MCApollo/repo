pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _libxvidcore4)"/usr/include "${PKG_DEST}"/usr/
cp -a "$(PKG_DEST_ _libxvidcore4)"/usr/lib/libxvidcore.dylib "${PKG_DEST}"/usr/lib/
