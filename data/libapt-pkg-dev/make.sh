pkg: mkdir -p /usr/lib /usr/include
cp -a "$(PKG_DEST_ _apt1.4)"/usr/lib/libapt-pkg.dylib "${PKG_DEST}"/usr/lib/
cp -a "$(PKG_DEST_ _apt1.4)"/usr/include/apt-pkg "${PKG_DEST}"/usr/include
