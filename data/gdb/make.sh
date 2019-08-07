shopt -s extglob
pkg:setup
cd src/gdb
autoconf
cd ../..
cd ..
mkdir build
cd build
PKG_CONF=$(echo ../!(build)/src/configure) pkg:configure
make
# XXX: do I really need DSTROOT?
pkg:install DSTROOT="${PKG_DEST}"
for bin in ar nm ranlib size strings strip; do
    pkg: rm -f "/usr/bin/${bin}"
done
pkg: rm -f /usr/lib/libiberty.a
ldid -S"${PKG_DATA}/gdb.xml" "${PKG_DEST}/usr/bin/gdb"
pkg: rm -rf /usr/share/locale
