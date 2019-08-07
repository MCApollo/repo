pkg:setup
cp -a "${PKG_DATA}"/*.[ch] .
declare -a flags
# XXX: don't use this on darwin8
flags[${#flags[@]}]=-DNEED_PSELECT
"${PKG_TARG}-gcc" -fno-common !(dns_async).c -o libresolv.9.dylib -dynamiclib -I. -linfo -install_name /usr/lib/libresolv.9.dylib -compatibility_version 1.0.0 "${flags[@]}" -save-temps
pkg: mkdir -p /usr/lib
pkg: ln -s libresolv.9.dylib /usr/lib/libresolv.dylib
