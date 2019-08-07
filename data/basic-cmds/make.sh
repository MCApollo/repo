pkg:setup
for bin in mesg write uudecode uuencode; do
    "${PKG_TARG}-gcc" -o "${bin}/${bin}" "${bin}"/*.c
    pkg:usrbin "${bin}/${bin}"
done
