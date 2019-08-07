pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _openssl0.9.8)"/usr/lib "${PKG_DEST}"/usr
pkg: rm -rf /usr/lib/{lib{ssl,crypto}.dylib,ssl,pkgconfig}
