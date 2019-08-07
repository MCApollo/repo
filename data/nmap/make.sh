pkg:setup
pushd libdnet-stripped
autoconf
popd
CPPFLAGS="-I$(PKG_DEST_ _lua5.3)/${PKG_TAPF}/include/lua5.3" \
pkg:configure --without-python --without-zenmap --enable-static=yes --without-nmap-update --disable-universal --enable-ipv6
pkg:make
pkg:install
#pkg: sed -ie 's|^#!.*|#!/usr/bin/env python|' /usr/bin/ndiff
pkg: rm /usr/bin/ndiff
