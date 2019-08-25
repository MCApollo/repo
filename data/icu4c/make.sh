pkg:setup
cd source
# Host build
mkdir host
cd host
../configure --enable-static --disable-shared 
make -j8
cd ..
pkg:configure --disable-samples --disable-tests --with-cross-build=$PWD/host
pkg:make 
pkg:install 
