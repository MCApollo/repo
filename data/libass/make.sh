pkg:setup
HARFBUZZ_CFLAGS="-I$(PKG_DEST_ harfbuzz)/${PKG_TAPF}/include/harfbuzz" \
pkg:configure --disable-dependency-tracking  --disable-fontconfig
pkg:install 
