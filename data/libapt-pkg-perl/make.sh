pkg:setup
echo 'INCLUDE = .' > config.in
echo 'LIB = .' >> config.in
export PERL_SRC="$(PKG_DEST_ perl)"
$(PKG_WORK_ perl)/perl-5*/miniperl_top Makefile.PL
env
pkg:make CC="${PKG_TARG}-g++" CCFLAGS="-std=c++11 -stdlib=libc++" LD="${PKG_TARG}-g++" LDDLFLAGS="-shared -std=c++11 -stdlib=libc++"
make pure_vendor_install DESTDIR="${PKG_DEST}"
