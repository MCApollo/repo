pkg: mkdir -p /usr/lib
for ver in 10.4 10.5; do
    libgcc=lib/libgcc_s.${ver}.dylib
    cp -a "/apl/sys/2b6/${libgcc}" "${PKG_DEST}/usr/lib"
done
for ver in 1; do
    libgcc=lib/libgcc_s.${ver}.dylib
    cp -a "/apl/sys/2b6/${libgcc}" "${PKG_DEST}/usr/lib"
    pkg: "${PKG_TARG}-strip" -x -no_uuid "/usr/${libgcc}"
    pkg: ldid -T- "/usr/${libgcc}"
done
