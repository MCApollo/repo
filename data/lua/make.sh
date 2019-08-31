pkg:setup
sed -i "s|/usr/local|${PKG_TAPF}|" src/luaconf.h
sed -i "s|@LUA_PREFIX@|${PKG_TAPF}|" src/Makefile
pkg:make PLAT=macosx PREFIX=${PKG_TAPF} AR=${PKG_TARG}-ar RANLIB=${PKG_TAPF}-ranlib
pkg:install PLAT=macosx PREFIX=${PKG_TAPF} AR=${PKG_TARG}-ar RANLIB=${PKG_TAPF}-ranlib

(
cd ${PKG_DEST}/${PKG_TAPF}/bin
ln -rs lua lua5.3
ln -rs lua lua-5.3
ln -rs luac luac5.3
ln -rs luac luac-5.3
cd ${PKG_DEST}/${PKG_TAPF}/include
ln -rs lua*/lua/* lua
cd ${PKG_DEST}/${PKG_TAPF}/lib
ln -rs liblua.5.3.dylib liblua5.3.dylib
mkdir pkgconfig; cd pkgconfig
cp ${PKG_DATA}/lua.pc .
sed -i "s|@PREFIX@|${PKG_TAPF}|" lua.pc
ln -rs lua.pc lua5.3.pc
ln -rs lua.pc lua-5.3.pc
)
