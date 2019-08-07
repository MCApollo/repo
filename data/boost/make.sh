shopt -s extglob
pkg:setup
./bootstrap.sh --prefix=/usr
#toolset=gcc-arm64 using gcc : arm64 : aarch64-apple-darwin17-g++ ;
echo "using clang : arm : ${PKG_TARG}-g++ ;" >>project-config.jam
./b2 install toolset=clang-arm abi=aapcs --prefix="${PKG_DEST}/usr" -j16
rm -f "${PKG_DEST}"/usr/lib/*-d?(-+([0-9_])).@(a|dylib)
for na in "${PKG_DEST}"/usr/lib/*-+([0-9_]).a; do
    a=${na/-+([0-9_]).a/.a}
    rm -f "$a"
    ln -s "$(basename "$na")" "$a"
done
