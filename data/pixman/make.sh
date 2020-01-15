pkg:setup
pkg:configure --disable-dependency-tracking --disable-gtk --disable-silent-rules 
pkg:install 

ln -rs ${PKG_DEST}/${PKG_TAPF}/include/pixman-*/* ${PKG_DEST}/${PKG_TAPF}/include/
