pkg:setup
cd pmset
touch powermanagement.h
"${PKG_TARG}-gcc" -o pmset pmset.c -framework CoreFoundation -framework IOKit -framework SystemConfiguration
pkg: mkdir -p /usr/bin
pkg: cp -a pmset /usr/bin
