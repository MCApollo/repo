pkg:setup
#pkg:configure --disable-unicode --disable-linux-affinity --libdir='${prefix}/local/lib' --disable-lzmadec --disable-lzmainfo --disable-lzma-links
pkg:configure --disable-lzmadec --disable-lzmainfo --disable-lzma-links --libdir="\${exec_prefix}/local/lib"
make -j8
pkg:install
pkg: sed -ie 's|/usr/local/lib|${prefix}/local/lib|' /usr/local/lib/pkgconfig/liblzma.pc
