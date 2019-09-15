pkg:setup
cd pyobjc-core

CFLAGS=(
'-g'
'-fexceptions'
'-Wall'
'-Wstrict-prototypes'
'-Wmissing-prototypes'
'-Wformat=2' 
'-W'
'-Wpointer-arith'
'-Wmissing-declarations'
'-Wnested-externs'
'-W'
'-Wno-import'
'-Wno-unknown-pragmas'
'-Wno-deprecated-declarations'
'-Wno-unused-command-line-argument'
'-Wshorten-64-to-32'
"-I$(PKG_DEST_ python)/${PKG_TAPF}/include/python3.7m"
"-I$(PKG_DEST_ libxml2)/${PKG_TAPF}/include/libxml2"
"-DPyObjC_BUILD_RELEASE=1014"
'-fno-common'
'-IModules/objc'
'-DPY_MAJOR_VERSION=3'
"-I$(xcrun -sdk macosx --show-sdk-path)/System/Library/Frameworks/Foundation.framework/Headers/"
"-I${PKG_DATA}/include"
# Include custom headers
'-include ios-include.h'
)

LDFLAGS=(
'-framework CoreFoundation'
'-framework Foundation'
'-fvisibility=protected'
'-g'
'-O3'
)

BANNED=(
'fsref.m'
'fsspec.m'
)

find Modules/objc/!(test) -name '*.m' -print0 | while read -d $'\0' -r m; do
    if echo "${BANNED[@]}" | grep "${m##*/}" &>/dev/null; then
       continue
    fi 
    o=${m%.m}.o
    mi=${m%.m}.mi
    echo "Compiling ${o}..."
    ${PKG_TARG}-clang -fmodules ${CFLAGS[@]} ${LDFLAGS[@]} -ObjC -c -o "$o" "$m" || exit 1
done || exit 1

${PKG_TARG}-gcc -dynamiclib -lpython3.7m -o _objc.dylib Modules/objc/*.o -lobjc -lffi -lxml2 ${LDFLAGS[@]} -framework Foundation

pkg: mkdir -p ${PKG_TAPF}/lib/python3.7/lib-dynload
pkg: cp -a _objc.dylib ${PKG_TAPF}/lib/python3.7/lib-dynload
pkg: cp -a Lib/objc ${PKG_TAPF}/lib/python3.7
