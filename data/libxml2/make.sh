shopt -s extglob
pkg: mkdir -p /usr/lib
cp -a "$(PKG_DEST_ _libxml2)"/usr/lib/!(*.dylib|*.la) "${PKG_DEST}"/usr/lib
cp -a "$(PKG_DEST_ _libxml2)"/usr/!(lib) "${PKG_DEST}"/usr
