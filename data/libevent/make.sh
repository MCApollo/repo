pkg:setup
./autogen.sh
pkg:configure --disable-dependency-tracking --disable-debug-mode 
pkg:make
pkg:install 
