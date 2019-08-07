pkg: mkdir -p /usr /usr/lib
cp -a "$(PKG_DEST_ _sqlite3)"/usr/lib/pkgconfig "${PKG_DEST}"/usr/lib
cp -a "$(PKG_DEST_ _sqlite3)"/usr/{bin,include} "${PKG_DEST}"/usr
