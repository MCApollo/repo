shopt -s extglob
pkg:setup
cd ..
dir=$(echo *)
mkdir bld-ncurses{,w}
cd bld-ncurses
flags="--with-shared --without-normal --without-debug --enable-sigwinch --disable-mixed-case --enable-termcap --enable-pc-files --with-pkg-config-libdir=${PKG_TAPF}/lib/pkgconfig"
PKG_CONF=../${dir}/configure PKG_MCPU=-marm pkg:configure ${flags}
make -j8
pkg:install
cd ../bld-ncursesw
PKG_CONF=../${dir}/configure PKG_MCPU=-marm pkg:configure ${flags} --disable-overwrite --enable-widec
make -j8
pkg:install

# In adv-cmds
pkg: rm /usr/bin/tabs
pkg: mkdir -p @/usr/lib
pkg: cp -aL /usr/lib/libcurses.dylib @/usr/lib/libcurses.dylib
pkg: cp -aL /usr/lib/libncurses.dylib @/usr/lib/libncurses.dylib

pkg: mkdir -p /usr/lib/_ncurses
pkg: mv /usr/lib/lib{,n}curses.dylib /usr/lib/_ncurses/
pkg: ln -s libncurses.6.dylib /usr/lib/libncurses6.dylib
pkg: ln -s libncursesw.6.dylib /usr/lib/libncursesw6.dylib
rm -f "${PKG_DEST}"/usr/lib/*.a

for ti in "${PKG_DEST}"/usr/share/terminfo/*/*; do
    if [[ ${ti} == */@(?(pc)ansi|cons25|cygwin|dumb|linux|mach|rxvt|screen|sun|vt@(52|100|102|220)|swvt25?(m)|[Exe]term|putty|konsole|gnome|apple|Apple_Terminal|unknown)?([-+.]*) ]]; then
        echo "keeping terminfo: ${ti}"
    else
        rm -f "${ti}"
    fi
done

rmdir --ignore-fail-on-non-empty "${PKG_DEST}"/usr/share/terminfo/*

for ti in "${PKG_DEST}"/usr/share/terminfo/*; do
    ln -Tsf "${ti##*/}" "${PKG_DEST}"/usr/share/terminfo/"$(printf "%02x" "'${ti##*/}")"
done
