pkg:setup
pkg:configure
make install DESTDIR=${PKG_DEST}

pkg: mkdir -p ${PKG_TAPF}/lib/pkgconfig
ln -rs ${PKG_DEST}/${PKG_TAPF}/share/pkgconfig/* ${PKG_DEST}/${PKG_TAPF}/lib/pkgconfig/
