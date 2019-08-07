pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _libvpx)"/usr/lib/{libvpx.dylib,pkgconfig} "${PKG_DEST}"/usr/lib
cp -a "$(PKG_DEST_ _libvpx)"/usr/include "${PKG_DEST}"/usr
