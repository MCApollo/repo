pkg:setup
./configure --prefix=/usr
make CC="${PKG_TARG}-gcc"
pkg:install
