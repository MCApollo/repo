pkg:setup
./autogen.sh
CXXFLAGS="-DNDEBUG -std=c++11" pkg:configure --disable-debug --disable-dependency-tracking --with-zlib
make
pkg:install 
