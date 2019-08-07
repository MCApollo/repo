pkg:setup
pkg:configure --disable-mac --disable-nls --without-gtk --enable-cli --enable-daemon
pkg:make
pkg:install
