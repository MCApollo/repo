shopt -s extglob
pkg:setup
cd ..
mv * target
pkg:extract
mv !(target) host
cd host
./configure
make
cd ../target
pkg:configure
make FILE_COMPILE="$(pwd)"/../host/src/file
pkg:install
