pkg:setup
cp -f ${PKG_BASE}/config.sub ./build
pkg:configure --disable-dependency-tracking  --sysconfdir=${PKG_TAPF}/etc --enable-accesslog --enable-auditlog --enable-bdb=no --enable-constraint --enable-dds --enable-deref --enable-dyngroup --enable-dynlist --enable-hdb=no --enable-memberof --enable-ppolicy --enable-proxycache --enable-refint --enable-retcode --enable-seqmod --enable-translucent --enable-unique --enable-valsort --with-yielding_select=yes	\
	CC=${PKG_TARG}-gcc LD=${PKG_TARG}-ld
# auto-tools is too old and needs a little help.
pkg:make
pkg:install
