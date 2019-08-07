pkg:setup
pkg:configure
cp -a "${PKG_DATA}"/linuxint.h raop_play
cp -a "${PKG_DATA}"/getline.[hc] rendezvous
cp -a "${PKG_DATA}"/getline.[hc] raop_play
make
pkg:install
