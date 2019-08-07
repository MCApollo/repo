pkg:setup
cd build/generic
pkg:configure --disable-assembly
pkg:make
pkg:install
pkg: rm /usr/lib/libxvidcore.a
pkg: ln -s libxvidcore.4.dylib /usr/lib/libxvidcore.dylib
