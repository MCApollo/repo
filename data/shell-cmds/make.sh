pkg:setup
mkdir -p "${PKG_DEST}/usr/bin"
for bin in killall renice script time which getopt; do
    ${PKG_TARG}-gcc -O2 -o "${bin}/${bin}" "${bin}"/*.c -D'__FBSDID(x)=' -save-temps
    cp -a "${bin}/${bin}" "${PKG_DEST}/usr/bin"
done
