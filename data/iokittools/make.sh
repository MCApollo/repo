shopt -s extglob
pkg:setup
pkg: mkdir -p /usr/sbin
for tproj in *.tproj; do
    tproj=$(basename "${tproj}" .tproj)
    ${PKG_TARG}-gcc -lcurses -o "${tproj}" "${tproj}.tproj"/*.c -framework CoreFoundation -framework IOKit -save-temps
    pkg: cp -a "${tproj}" /usr/sbin
done
# In firmware-sbin
pkg: rm /usr/sbin/ioreg
