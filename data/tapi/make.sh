set -x
pkg:setup
mkdir include
DERIVED_FILE_DIR=`pwd`/include IPHONEOS_DEPLOYMENT_TARGET=11.0 src/create_configure
for cfile in $(find src -name '*.c'); do
  basename=$(basename $cfile .c)
  ${PKG_TARG}-gcc -o $basename.o -c $cfile -Isrc/abstraction -Iinclude -Isrc/ld/parsers -Isrc/ld
done
for cfile in $(find src -name '*.m'); do
  basename=$(basename $cfile .m)
  ${PKG_TARG}-gcc -ObjC -o $basename.o -c $cfile -Isrc/abstraction -Iinclude -Isrc/ld/parsers -Isrc/ld
done
for cppfile in $(find src -name '*.cpp'); do
  basename=$(basename $cppfile .cpp)
  ${PKG_TARG}-g++ -std=c++11 -o $basename.o -c $cppfile -Isrc/abstraction -Iinclude -Isrc/ld/parsers -Isrc/ld
done
cp  src/other/PruneTrie.o .
${PKG_TARG}-gcc -o PruneTrie.o -c src/other/PruneTrie.cpp  -Isrc/abstraction -Iinclude -Isrc/ld/parsers -Isrc/ld
${PKG_TARG}-ar -r libprunetrie.a PruneTrie.o
pkg: mkdir -p /usr/lib /usr/include/mach-o
pkg: cp libprunetrie.a /usr/lib
pkg: cp src/other/prune_trie.h /usr/include/mach-o
