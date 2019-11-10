pkg:setup
pkg:make -f Makefile.osx

pkg: mkdir -p ${PKG_TAPF}/{bin,lib/pkgconfig,include}
X=${PKG_DEST}/${PKG_TAPF}
cp bin/rubberband ${X}/bin
cp -r rubberband ${X}/include/ 
cp lib/librubberband.dylib ${X}/lib/librubberband.2.1.1.dylib
pkg: ln -rs ${PKG_TAPF}/lib/librubberband.2.1.1.dylib ${PKG_TAPF}/lib/librubberband.2.dylib
pkg: ln -rs ${PKG_TAPF}/lib/librubberband.2.1.1.dylib ${PKG_TAPF}/lib/librubberband.dylib

sed -i "s|%PREFIX%|${PKG_TAPF}|" rubberband.pc.in
cp rubberband.pc.in ${X}/lib/pkgconfig/rubberband.pc
