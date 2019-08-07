pkg:setup
autoconf
pkg:configure
make
pkg: mkdir -p /usr/sbin
pkg: cp -a sniffit /usr/sbin
