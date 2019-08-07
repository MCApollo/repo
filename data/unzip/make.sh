pkg:setup
cp unix/Makefile .
make unzips CC=${PKG_TARG}-gcc CF='-O3 -Wall -I. -DBSD -DUNIX' LF2=
pkg:usrbin unzip funzip unzipsfx
