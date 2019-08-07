pkg:setup
cp "${PKG_DATA}"/gas-preprocessor.pl .
# Host requires perl.
CC="${PKG_TARG}-gcc" AS="./gas-preprocessor.pl -arch $(echo ${PKG_TARG} | sed -e 's/-.*//') -- ${PKG_TARG}-gcc" pkg:configure --enable-shared --disable-lsmash --enable-strip --cross-prefix="${PKG_TARG}-" --system-libx264
pkg:make
pkg:install
