pkg:setup
pkg: mkdir -p ${PKG_TAPF}/{bin,lib,include}
pkg:install SYS=darwin prefix=${PKG_TAPF} sbindir=${PKG_TAPF}/bin 
pkg: rm ${PKG_TAPF}/lib/librtmp.a || :
