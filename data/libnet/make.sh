# From elucubratus.
pkg:setup
autoreconf -fvi
pkg:configure --with-link-layer=bpf --disable-dependency-tracking ac_cv_libnet_endianess=lil ac_libnet_have_packet_socket=no ac_cv_libnet_linux_procfs=no ac_cv_lbl_unaligned_fail=no
sed -i 's|#include <net/bpf.h>||' src/libnet_link_bpf.c 
pkg:install 
