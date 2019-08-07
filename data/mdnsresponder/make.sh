pkg:setup
"${PKG_TARG}"-gcc -o dns-sd Clients/dns-sd.c
pkg: mkdir -p /usr/bin
pkg: cp -a dns-sd /usr/bin
