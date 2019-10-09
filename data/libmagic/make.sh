pkg:setup
# Host
./configure --prefix=${PWD}/host
make install; make distclean
export PATH=${PWD}/host/bin:${PATH}
# Target
pkg:configure --disable-dependency-tracking --disable-silent-rules  --enable-fsect-man5 
pkg:install 

pkg: mkdir -p ${PKG_TAPF}/share/misc/magic
cp magic/Magdir/* ${PKG_DEST}/${PKG_TAPF}/share/misc/magic/

