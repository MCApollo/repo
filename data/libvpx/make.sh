pkg:setup
CROSS="${PKG_TARG}-" ./configure --target="${PKG_TARG}-gcc" --prefix=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix") --disable-static --enable-shared --enable-examples \
    --enable-pic \
    --enable-shared \
    --disable-install-bins \
    --disable-install-srcs \
    --size-limit=16384x16384 \
    --enable-postproc \
    --enable-multi-res-encoding \
    --enable-temporal-denoising \
    --enable-vp9-temporal-denoising \
    --enable-vp9-postproc
pkg:make V=1
pkg:install
