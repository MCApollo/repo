pkg:setup
pkg: mkdir -p /usr/bin

${PKG_TARG}-gcc -o hexdump/hexdump hexdump/{conv,display,hexdump,hexsyntax,odsyntax,parse}.c -D'__FBSDID(x)=' -D__DARWIN_C_LEVEL=200112L
pkg: cp -a hexdump/hexdump /usr/bin

for bin in ctags error rpcgen unifdef; do
    ${PKG_TARG}-gcc -o "${bin}/${bin}" "${bin}"/*.c -D_POSIX_C_SOURCE=200112L -DS_IREAD=S_IRUSR -DS_IWRITE=S_IWUSR
    pkg: cp -a "${bin}/${bin}" /usr/bin
done
