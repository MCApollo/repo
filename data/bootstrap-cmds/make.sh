pkg:setup
cd migcom.tproj
cp -a i386 arm
yacc -d parser.y -o parser.c
lex lexxer.l
${PKG_TARG}-gcc -o migcom *.c -save-temps
pkg: mkdir -p /usr/bin /usr/libexec
pkg: cp -a migcom /usr/libexec
pkg: cp -a mig.sh /usr/bin/mig
