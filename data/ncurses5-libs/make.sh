shopt -s extglob
pkg:setup
cd ..
dir=$(echo *)
mkdir bld-ncurses{,w}
cd bld-ncurses
flags='--with-shared --without-normal --without-debug --enable-sigwinch --disable-mixed-case --enable-termcap'
PKG_CONF=../${dir}/configure PKG_MCPU=-marm pkg:configure ${flags}
make -j8
pkg: mkdir -p /usr/lib
cd lib
for lib in *.5.dylib; do
	pkg: cp ${lib} /usr/lib/
	pkg: ln -s ${lib} /usr/lib/$(basename ${lib} .5.dylib)5.dylib
done
cd ..
cd ../bld-ncursesw
PKG_CONF=../${dir}/configure PKG_MCPU=-marm pkg:configure ${flags} --disable-overwrite --enable-widec
make -j8
cd lib
for lib in *.5.dylib; do
	pkg: cp ${lib} /usr/lib
	pkg: ln -s ${lib} /usr/lib/$(basename ${lib} .5.dylib)5.dylib
done
cd ..
