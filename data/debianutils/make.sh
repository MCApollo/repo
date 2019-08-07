pkg:setup
pkg:configure
make
pkg: mkdir -p /bin
pkg: cp -a run-parts /bin
