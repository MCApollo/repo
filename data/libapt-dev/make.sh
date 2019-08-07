pkg: mkdir -p /usr/lib
find "$(PKG_DEST_ _apt1.4)"/usr/lib -maxdepth 1 -type l -exec cp {} "${PKG_DEST}"/usr/lib/ \;
rm -rf "${PKG_DEST}"/usr/lib/libapt-pkg* "${PKG_DEST}"/usr/lib/lib*.*.dylib
