pkg:setup
autoconf
cd regex-0.12
autoconf
cd ..
pkg:configure "--with-pcap-includes=${PKG_ROOT}/usr/include"
make
pkg:install
