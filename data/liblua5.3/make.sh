pkg: mkdir -p /usr/lib
LIBNAME=${PKG_NAME#lib}
cp -a "$(PKG_DEST_ _${LIBNAME})"/usr/lib/lib*.dylib "${PKG_DEST}"/usr/lib
