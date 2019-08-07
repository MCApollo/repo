pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure --with-xml2-config="$(PKG_DEST_ libxml2)/usr/bin/xml2-config" --with-lzma="$(PKG_DEST_ liblzma)/usr"
make
pkg:install
