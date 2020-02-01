pkg:setup
# pkg-config wrapper
mkdir bin
printf '#!/bin/bash\n%s $@' "${PKG_BASE}/util/pkg-config.sh" > bin/${PKG_TARG}-pkg-config
chmod +x bin/${PKG_TARG}-pkg-config

PATH="${PWD}/bin:${PATH}" \
./configure --cpu=aarch64 --cross-prefix=${PKG_TARG}- --enable-curses --disable-bsd-user --disable-guest-agent --disable-cocoa --disable-sdl --disable-gtk --prefix=${PKG_TAPF} --enable-libssh --enable-vde --disable-kvm --enable-modules --extra-cflags="-isystem ${PKG_DATA}/libucontext -include ucontext.h -std=gnu99" --extra-cxxflags="-isystem ${PKG_DATA}/libucontext -include ucontext.h" --extra-ldflags="${PKG_DATA}/libucontext/libucontext.a" --target-list="i386-softmmu,arm-softmmu,x86_64-softmmu,aarch64-softmmu,riscv64-softmmu,ppc64-softmmu,mips64-softmmu,sparc64-softmmu" --disable-strip --disable-debug-tcg --enable-malloc-trim
# --enable-debug-info --enable-debug --enable-debug-tcg --disable-stack-protector
pkg:install V=1

ldid -S${PKG_DATA}/qemu.xml ${PKG_DEST}/${PKG_TAPF}/bin/*
