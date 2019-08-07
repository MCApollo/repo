pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _libopus)"/usr/{include,share} "${PKG_DEST}"/usr/
cp -a "$(PKG_DEST_ _libopus)"/usr/lib/{lib*.dylib,pkgconfig} "${PKG_DEST}"/usr/lib
rm "${PKG_DEST}"/usr/lib/lib*.*.dylib
