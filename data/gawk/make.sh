pkg:setup
pkg:configure
make
pkg:install
rm -f "${PKG_DEST}"/usr/bin/{pgawk*,gawk-*}
