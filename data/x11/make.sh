pkg:setup
pkg:configure --enable-malloc0returnsnull
gcc -c -o src/util/makekeys-makekeys.o src/util/makekeys.c -Iinclude
gcc -o src/util/makekeys src/util/makekeys-makekeys.o
make -j8
pkg:install
