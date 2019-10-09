pkg:setup
sed -i -e 's/gcc/$(CC)/' -e 's/libnet-config/true/' Makefile
pkg:make
pkg: mkdir -p ${PKG_TAPF}/bin 
cp arpoison ${PKG_DEST}/${PKG_TAPF}/bin
