pkg:setup
pkg:configure  --sysconfdir=${PKG_TAPF}/etc --with-ssl=openssl --disable-debug --disable-pcre --disable-pcre2 --without-libpsl
pkg:install 
