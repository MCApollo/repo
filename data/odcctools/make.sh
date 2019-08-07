pkg:setup
pkg: export RC_ProjectSourceVersion="$(cat ${PKG_DATA}/_metadata/version)"
pkg:make DSTROOT="${PKG_DEST}" SDKROOT="${PKG_ROOT}"
pkg:install DSTROOT="${PKG_DEST}" SDKROOT="${PKG_ROOT}"
pkg: rm -f /usr/lib/system/libmacho.dylib /usr/bin/{nm,otool,size}
pkg: mv -f /usr/bin/ar{,-classic}
pkg: ln -s llvm-ar /usr/bin/ar
pkg: mv -f /usr/bin/ranlib{,-classic}
pkg: ln -s llvm-ranlib /usr/bin/ranlib
pkg: mv -f /usr/bin/nm{-classic,}
pkg: mv -f /usr/bin/otool{-classic,}
pkg: mv -f /usr/bin/size{-classic,}
