pkg:setup
# pkg-config wrapper
mkdir bin
printf '#!/bin/bash\n%s $@' "${PKG_BASE}/util/pkg-config.sh" > bin/${PKG_TARG}-pkg-config
chmod +x bin/${PKG_TARG}-pkg-config

PATH="${PWD}/bin:${PATH}" ./configure --cpu=aarch64 --cross-prefix=${PKG_TARG}- --enable-curses --extra-cflags="-DNCURSES_WIDECHAR=1"  --disable-cocoa --disable-sdl --disable-gtk --prefix=${PKG_TAPF} --enable-pie --enable-libssh --enable-vde --disable-kvm --enable-modules --disable-coroutine-pool --disable-strip  --enable-tcg-interpreter --enable-debug-info --enable-debug
# FIXME: gthreads on qemu.
sed -i "s/CONFIG_COROUTINE_BACKEND=sigaltstack/CONFIG_COROUTINE_BACKEND=gthread/" config-host.mak
pkg:install V=1

# ldid -S${PKG_DATA}/qemu.xml ${PKG_DEST}/${PKG_TAPF}/bin/*
