${PKG_TARG}-gcc -o _uicaboodle.dylib "${PKG_DATA}/uicaboodle.m" -I"$(PKG_DEST_ python)"/usr/include/python2.7 -I "$(PKG_WORK_ pyobjc)"/*/pyobjc-core/Modules/objc -lpython2.7 -framework UIKit -dynamiclib -framework Foundation -lobjc -framework CoreFoundation
pkg: mkdir -p /usr/lib/python2.7/lib-dynload
pkg: cp -a _uicaboodle.dylib /usr/lib/python2.7/lib-dynload
