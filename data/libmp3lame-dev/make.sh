pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _lame)"/usr/include "${PKG_DEST}"/usr/
cp -a "$(PKG_DEST_ _lame)"/usr/lib/lib*.dylib "${PKG_DEST}"/usr/lib
rm "${PKG_DEST}"/usr/lib/lib*.*.dylib
