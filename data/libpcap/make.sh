pkg:setup
pkg:configure  --enable-ipv6 --disable-universal --with-pcap=bpf CFLAGS="-O2 -fno-common -D__APPLE__ -DPRIVATE"
pkg:install 
