pkg:setup
cd lsof
yes n | ./Configure darwin
make CC="${PKG_TARG}-gcc" 2>&1 AR="${PKG_TARG}-ar cr \${LIB} \${OBJ}"
pkg: mkdir -p /usr/bin
pkg: cp -a lsof /usr/bin
