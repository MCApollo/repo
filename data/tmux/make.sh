pkg:setup
LDFLAGS="-lresolv" pkg:configure --sysconf=${PKG_TAPF}/etc
pkg:install 
