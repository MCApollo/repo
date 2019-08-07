pkg: mkdir -p /usr/lib/pkgconfig /usr/include
LIBNAME=${PKG_NAME%-dev}
LIBNAME=${LIBNAME#lib}
cp -a "$(PKG_DEST_ _ffmpeg)"/usr/lib/lib${LIBNAME}.dylib "${PKG_DEST}"/usr/lib/
cp -a "$(PKG_DEST_ _ffmpeg)"/usr/lib/pkgconfig/lib${LIBNAME}.pc "${PKG_DEST}"/usr/lib/pkgconfig/
cp -a "$(PKG_DEST_ _ffmpeg)"/usr/include/lib${LIBNAME} "${PKG_DEST}"/usr/include/
