pkg:setup
cd src
"${PKG_TARG}-gcc" -o class-dump -ObjC *.m -Wall -include Foundation/Foundation.h -Wno-trigraphs -fpascal-strings -fasm-blocks -O0 -Wreturn-type -Wunused-variable -DHANDLE_OBJC2_ABI -framework CoreFoundation -lobjc -framework Foundation
pkg: mkdir -p /usr/bin
pkg: cp -a class-dump /usr/bin
