pkg:setup
pkg:configure --with-installed-glib
make -j8
pkg:install
