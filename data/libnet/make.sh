pkg:setup
autoreconf -fvi
pkg:configure --disable-dependency-tracking
sed -i 's|#include <net/bpf.h>||' src/libnet_link_bpf.c 
pkg:install 
