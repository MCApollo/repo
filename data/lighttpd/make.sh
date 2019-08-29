pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules --with-openssl --with-ldap --with-zlib --with-bzip2 --with-pcre=$(PKG_DEST_ pcre)/${PKG_TAPF}
pkg:install

# TODO: sendfile == crashes?
