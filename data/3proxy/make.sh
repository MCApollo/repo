pkg:extract
pkg:patch
make -f Makefile.unix {CC,LN}="${PKG_TARG}-gcc"
pkg: mkdir -p /usr/bin
pkg: cp -a src/{3proxy,dighosts,ftppr,mycrypt,pop3p,proxy,socks,tcppm,udppm} /usr/bin
