pkg:setup
pkg:configure --enable-pc-files --with-pkg-config-libdir=${PKG_TAPF}/lib/pkgconfig --enable-sigwinch --enable-symlinks --enable-widec --with-shared --with-gpm=no
pkg:install 

# Install symlinks
# libs
for x in ${PKG_DEST}/${PKG_TAPF}/lib/*.{dylib,a}; do 
	x=${x##*/}
	pkg: ln -rs ${PKG_TAPF}/lib/${x} ${PKG_TAPF}/lib/${x//w}
done
pkg: ln -rs ${PKG_TAPF}/lib/{libncurses.a,libcurses.a}
pkg: ln -rs ${PKG_TAPF}/lib/{libncurses.dylib,libcurses.dylib}
# pkg-config files.
pkg: ln -rs ${PKG_TAPF}/lib/pkgconfig/{ncursesw.pc,ncurses.pc}
# ncursesw-config -> ncurses-config
#x=${PKG_DEST}/${PKG_TAPF}/bin/*-config
#x=${x##*/}
#pkg: ln -rs ${PKG_TAPF}/bin/${x} ${PKG_TAPF}/bin/${x//w}
# Move headers

#for x in curses.h form.h ncurses.h panel.h term.h termcap.h; do
	pkg: ln -rs ${PKG_TAPF}/include/ncursesw/* ${PKG_TAPF}/include/
#done
