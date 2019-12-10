pkg:setup
sed -i "s/pthread-stubs//" configure 
pkg:configure --without-doxygen
pkg:install
