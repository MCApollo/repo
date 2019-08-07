pkg:setup
pkg: cp %/entitlement.xml .
ln -s ~/theos-rp theos
make -j8 stage
pkg: cp -a .theos/_/. /
