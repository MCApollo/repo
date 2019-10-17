pkg:setup
pkg:make whois HAVE_ICONV=1 LDFLAGS="-liconv"
pkg: mkdir -p ${PKG_TAPF}/bin
cp whois ${PKG_DEST}/${PKG_TAPF}/bin/
