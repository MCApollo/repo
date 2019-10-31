pkg:setup
# pkg-config wrapper
mkdir bin
printf '#!/bin/bash\n%s $@' "${PKG_BASE}/util/pkg-config.sh" > bin/${PKG_TARG}-pkg-config
chmod +x bin/${PKG_TARG}-pkg-config

PATH="${PWD}/bin:${PATH}" ./configure --cpu=aarch64 --cross-prefix=${PKG_TARG}- --enable-curses --extra-cflags=-DNCURSES_WIDECHAR=1 --disable-cocoa --disable-sdl --disable-gtk --prefix=${PKG_TAPF} --enable-debug-info --enable-debug --target-list=i386-softmmu --enable-tcg-interpreter --enable-debug-info --enable-debug --disable-capstone --enable-pie  --enable-libssh --enable-vde 
pkg:install V=1
