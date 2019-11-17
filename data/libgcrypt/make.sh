pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules --disable-asm --disable-jent-support --with-gpg-error-prefix=$(PKG_DEST_ libgpg-error)/${PKG_TAPF}
make
pkg:install
