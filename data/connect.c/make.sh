pkg: ${PKG_TARG}-gcc -o connect %/connect.c -lresolv
pkg: mkdir -p /usr/bin
pkg: cp -a connect /usr/bin
