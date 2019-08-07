pkg:setup
make bzip2 bzip2recover CC=${PKG_TARG}-gcc CFLAGS='-Wall -Winline -O2'
pkg: mkdir -p /bin
pkg: cp -a bzip2 bzip2recover /bin
pkg: ln -s bzip2 /bin/bunzip2
pkg: ln -s bzip2 /bin/bzcat
