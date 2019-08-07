pkg: mkdir -p /usr/lib
LIBNAME=${PKG_NAME%%[[:digit:]]*}
LIBVER=${PKG_NAME#${LIBNAME}}
LIBNAME=${LIBNAME#lib}
cp -a "$(PKG_DEST_ _ffmpeg)"/usr/lib/lib${LIBNAME}.${LIBVER}.*dylib "${PKG_DEST}"/usr/lib
