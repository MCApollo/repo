pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _sqlite3)"/usr/lib "${PKG_DEST}"/usr
rm -rf "${PKG_DEST}"/usr/lib/pkgconfig
