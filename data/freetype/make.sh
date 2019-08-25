pkg:setup
pkg:configure  --enable-freetype-config --without-harfbuzz
make
pkg:install 

