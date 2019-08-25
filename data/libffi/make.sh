pkg:setup
pkg:configure --disable-debug --disable-dependency-tracking 
pkg:install 

pkg: mkdir -p ${PKG_TAPF}/include
ln -rs ${PKG_DEST}/${PKG_TAPF}/lib/*/include/*  ${PKG_DEST}/${PKG_TAPF}/include/
