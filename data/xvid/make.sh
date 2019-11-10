pkg:setup
cd build/generic
pkg:configure --disable-assembly 
make
pkg:install 
