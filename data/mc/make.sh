pkg:setup
pkg:configure --with-screen=ncurses --without-x
make -j8
pkg:install
