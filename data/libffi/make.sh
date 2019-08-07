pkg:setup
autoreconf -f -i
pkg:configure
pkg:make
pkg:install
pkg: rm -rvf /usr/share
