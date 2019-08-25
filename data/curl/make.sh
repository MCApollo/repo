pkg:setup
pkg:configure --disable-debug --disable-dependency-tracking --disable-silent-rules  --with-darwinssl --without-ca-bundle --without-ca-path ac_cv_file___dev_urandom_=yes
pkg:install 
pkg:install -C scripts

pkg: mkdir ${PKG_TAPF}/libexec
cp lib/mk-ca-bundle.pl ${PKG_DEST}/${PKG_TAPF}/libexec
