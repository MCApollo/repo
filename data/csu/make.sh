pkg:setup
pkg: mkdir -p /usr/lib
cp -a *.o "${PKG_DEST}"/usr/lib
pkg: ln -s crt1.o /usr/lib/crt1.10.5.o
pkg: ln -s dylib1.o /usr/lib/dylib1.10.5.o
