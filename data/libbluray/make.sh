pkg:setup
CFLAGS="-fno-stack-check -D_DARWIN_C_SOURCE" \
pkg:configure --disable-dependency-tracking --disable-bdjava-jar
make
pkg:install 
