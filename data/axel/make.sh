pkg:setup
./autogen.sh
pkg:configure --disable-dependency-tracking  --sysconfdir=${PKG_TAPF}/etc CFLAGS="-D_DARWIN_C_SOURCE"
pkg:install 
