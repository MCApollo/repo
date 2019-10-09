shopt -s extglob
pkg:setup
./bootstrap.sh --prefix=${PKG_TAPF} --without-libraries=python,mpi
echo "using clang : arm : ${PKG_TARG}-g++ ;" >>project-config.jam
./b2 install toolset=clang-arm abi=aapcs --prefix="${PKG_DEST}${PKG_TAPF}" -j8
rm -f "${PKG_DEST}"${PKG_TAPF}/lib/*-d?(-+([0-9_])).@(a|dylib)
for na in "${PKG_DEST}"${PKG_TAPF}/lib/*-+([0-9_]).a; do
    a=${na/-+([0-9_]).a/.a}
    rm -f "$a"
    ln -s "$(basename "$na")" "$a"
done
