pkg:setup
cp ${PKG_DATA}/gas-preprocessor.pl .
AS="./gas-preprocessor.pl -arch $(echo ${PKG_TARG} | sed -e 's/-.*//') -- ${PKG_TARG}-gcc" \
CC="${PKG_TARG}-gcc" \
CFLAGS="-fno-stack-check" \
pkg:configure --disable-lsmash --disable-swscale --disable-ffms --enable-strip --cross-prefix="${PKG_TARG}-" --enable-shared
make install DESTDIR=${PKG_DEST}
