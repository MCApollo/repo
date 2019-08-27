pkg:setup

sed -i 's|make_unique|std::make_unique|' src/bignum.h
sed -i 's|-std=c++11|-std=c++14|' configure

pkg:configure --disable-dependency-tracking  --with-openssl --with-libssh2 --without-openssl --without-gnutls --without-libgmp --without-libnettle --without-libgcrypt --without-appletls
pkg:install 

# TODO: bash_completion.install doc/bash_completion/aria2c
