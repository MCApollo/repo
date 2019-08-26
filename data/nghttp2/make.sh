pkg:setup
pkg:configure --disable-silent-rules --enable-app --disable-python-bindings
make
pkg:install 
