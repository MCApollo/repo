pkg:setup
pkg:configure --with-pcap=bpf --disable-universal CFLAGS="-O2 -fno-common -D__APPLE__ -DPRIVATE"
make
mkdir -p "${PKG_DEST}/usr/lib"
pkg: mkdir -p /usr/bin
make install install-shared DESTDIR="${PKG_DEST}"
pkg: rm -f /usr/lib/libpcap.a
