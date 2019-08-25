pkg:setup
make CC=${PKG_TARG}-gcc		\
	CXX=${PKG_TARG}-g++	\
	LD=${PKG_TARG}-g++	\
	LIBS="-lreadline -lncurses"

pkg: mkdir -p ${PKG_TAPF}/bin
cp aamath ${PKG_DEST}/${PKG_TAPF}/bin
