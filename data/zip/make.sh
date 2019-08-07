unzip "${PKG_DATA}/zip232.zip" -d zip-2.32
cd *
pkg:patch
cp unix/Makefile .
make zips CC="${PKG_TARG}-gcc" CPP="${PKG_TARG}-gcc -E"
pkg:usrbin zip zipcloak zipnote zipsplit
