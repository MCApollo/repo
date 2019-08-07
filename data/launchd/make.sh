pkg:extract
cd *
pkg:patch 
#${PKG_TARG}-gcc -c liblaunch/liblaunch.c -o liblaunch.o -Isrc -miphoneos-version-min=11.0 -Iliblaunch
${PKG_TARG}-gcc -DPRIVATE support/launchctl.c -o launchctl -Isrc -miphoneos-version-min=11.0 -Iliblaunch -I"$(PKG_DEST_ readline)/usr/include" -framework CoreFoundation -framework IOKit -lreadline -llaunch
pkg: mkdir -p /usr/bin
pkg: cp -a launchctl /usr/bin
