pkg:setup
mkdir binary
"${PKG_TARG}"-gcc -o binary/xpwntool -Iincludes common/abstractfile.c -lcrypto ipsw-patch/{8900,ibootim,img2,img3,libxpwn,lzss,lzssfile,nor_files,xpwntool}.c -lpng -lz
"${PKG_TARG}"-gcc -o binary/dmg -DHAVE_CRYPT {common/*,dmg/!(win32test),hfs/!(hfs)}.c -Iincludes -lz -lcrypto
"${PKG_TARG}"-gcc -o binary/hfs {common,hfs}/*.c -Iincludes -lz
pkg: mkdir -p /usr/bin
pkg: cp -a binary/* /usr/bin
