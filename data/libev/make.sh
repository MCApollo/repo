pkg:setup
pkg:configure --disable-dependency-tracking  
pkg:install 

pkg: rm ${PKG_TAPF}/include/event.h

