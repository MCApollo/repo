pkg:setup
cd src
make CC=${PKG_TARG}-gcc CXX=${PKG_TARG}-g++
pkg: mkdir -p /usr/lib /usr/include
pkg: cp -a libdict.a /usr/lib
pkg: cp -a include/*.{h,hpp} /usr/include
