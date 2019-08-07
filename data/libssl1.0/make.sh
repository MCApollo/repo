pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _openssl1.0)"/usr/lib "${PKG_DEST}"/usr
pkg: rm -rf /usr/lib/{lib{ssl,crypto}.dylib,ssl,pkgconfig}
