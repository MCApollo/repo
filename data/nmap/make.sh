pkg:setup
( cd libdnet-stripped; autoconf; )
pkg:configure  --with-libdnet=included --with-libssh2=yes --with-libpcre=system --with-liblua=system --with-libpcap=system --without-nmap-update --disable-universal --without-zenmap --enable-ipv6 --without-python --enable-static=yes
make
pkg:install
