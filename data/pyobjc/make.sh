shopt -s extglob

pkg:setup
cd pyobjc-core

find Modules/objc/!(test) -name '*.m' -print0 | while read -d $'\0' -r m; do
    o=${m%.m}.o
    mi=${m%.m}.mi
    echo ${PKG_TARG}-gcc -framework Foundation -O2 -I"$(PKG_DEST_ libxml2)"/usr/include/libxml2 -I"$(PKG_DEST_ python)"/usr/include/python2.7 -ObjC -c -o "$o" "$m" -IModules/objc -fno-common || exit 1
    ${PKG_TARG}-gcc -framework Foundation -O2 -I"$(PKG_DEST_ libxml2)"/usr/include/libxml2 -I"$(PKG_DEST_ python)"/usr/include/python2.7 -ObjC -c -o "$o" "$m" -IModules/objc -fno-common || exit 1
done || exit 1

${PKG_TARG}-gcc -O2 -dynamiclib -lpython2.7 -o _objc.dylib Modules/objc/*.o -lobjc -lffi -lxml2 -framework CoreFoundation -framework Foundation

pkg: mkdir -p /usr/lib/python2.7/lib-dynload
pkg: cp -a _objc.dylib /usr/lib/python2.7/lib-dynload
pkg: cp -a Lib/objc /usr/lib/python2.7
