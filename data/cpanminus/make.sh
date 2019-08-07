pkg:setup
echo 'INCLUDE = .' > config.in
echo 'LIB = .' >> config.in
export PERL_SRC="$(PKG_DEST_ perl)"
$(PKG_WORK_ perl)/perl-5*/miniperl_top Makefile.PL
pkg:make
make pure_vendor_install DESTDIR="${PKG_DEST}"
