pkg:setup
pkg:configure  --enable-freetype-config --without-harfbuzz
make
pkg:install 

ln -rs ${PKG_DEST}/${PKG_TAPF}/include/freetype2/* ${PKG_DEST}/${PKG_TAPF}/include/
