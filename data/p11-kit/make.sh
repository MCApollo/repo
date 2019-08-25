pkg:setup
export FAKED_MODE=1
pkg:configure --disable-dependency-tracking --disable-silent-rules --disable-trust-module  --sysconfdir=${PKG_TAPF}/etc --with-module-config=${PKG_TAPF}/etc/pkcs11/modules --without-libtasn1
pkg:make
pkg:install 
