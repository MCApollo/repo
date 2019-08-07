pkg: mkdir -p /usr/lib /usr/include
cp -a "$(PKG_DEST_ _openssl1.0)"/usr/lib/{lib{ssl,crypto}.dylib,pkgconfig} "${PKG_DEST}"/usr/lib
cp -a "$(PKG_DEST_ _openssl1.0)"/usr/include "${PKG_DEST}"/usr
