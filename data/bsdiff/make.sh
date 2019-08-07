pkg:setup

for bin in bsdiff bspatch; do
    "${PKG_TARG}-gcc" -o "${bin}" "${bin}.c" -lbz2
done

pkg: mkdir -p /usr/bin
pkg: cp -a bsdiff bspatch /usr/bin
