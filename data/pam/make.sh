pkg:setup
cd pam
pkg:configure --enable-giant-libpam # --enable-dynamic-libpam --enable-static-libpam
sed -e "s/gcc/${PKG_TARG}-clang/" -e "s/cc/${PKG_TARG}-clang/" -i Make.Rules
sed -i "s|/usr/lib|${PKG_TAPF}/lib|" Makefile */Makefile
mkdir pam
ln -rs *.h pam
make GIANT_LIBPAM=yes 
make GIANT_LIBPAM=no STATIC_LIBPAM=no
make install FAKEROOT=${PKG_DEST} INCLUDED=${PKG_TAPF}/include MANDIR=${PKG_TAPF}/share/man

[[ ! "${PKG_TAPF}" == "/usr" ]] && pkg: rm -rf ./usr || :
