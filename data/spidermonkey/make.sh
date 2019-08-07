pkg:setup
cd src
mkdir Darwin_DBG.OBJ
cp -a "${PKG_DATA}"/jsautocfg.h Darwin_DBG.OBJ
make -f Makefile.ref
pkg: mkdir -p /usr/bin /usr/lib
pkg: cp -a Darwin_DBG.OBJ/libjs.dylib /usr/lib
pkg: cp -a Darwin_DBG.OBJ/js /usr/bin
