pkg:setup
cp -a "${PKG_DATA}/getiopolicy_np.c" .
#${PKG_TARG}-gcc -o kextload kextload_main.c  -framework CoreFoundation utility.c -framework IOKit getiopolicy_np.c -DPRIVATE
${PKG_TARG}-gcc -o kextstat kextstat_main.c
${PKG_TARG}-gcc -o kextfind kextfind_*.c  -framework IOKit -framework CoreFoundation QEQuery.c utility.c getiopolicy_np.c -DPRIVATE
${PKG_TARG}-gcc -I. -o kextunload kextunload_main.c  -framework CoreFoundation  -framework IOKit utility.c getiopolicy_np.c  -DPRIVATE
${PKG_TARG}-gcc -o kextlibs kextlibs_main.c -framework IOKit -framework CoreFoundation utility.c getiopolicy_np.c -DPRIVATE
${PKG_TARG}-gcc -o kextsymboltool kextsymboltool.c
${PKG_TARG}-gcc -o mkextunpack mkextunpack_main.c -framework CoreFoundation compression.c
#${PKG_TARG}-gcc -o kextd kextd_main.c -framework CoreFoundation -framework IOKit getiopolicy_np.c -DPRIVATE logging.c request.c PTLock.c watchvol.c bootcaches.c utility.c safecalls.c
#${PKG_TARG}-gcc -o kextcache kextcache_main.c -framework CoreFoundation -framework IOKit utility.c prelink.c mkext_file.c logging.c arch.c bootcaches.c compression.c safecalls.c update_boot.c getiopolicy_np.c -DPRIVATE
# XXX: these files shouldn't go in /usr/bin
pkg: mkdir -p /sbin /usr/bin /usr/sbin
pkg: cp -a kextfind kextlibs kextsymboltool /usr/bin
#pkg: cp -a kextd /usr/libexec
pkg: cp -a kextunload /sbin #kextload
pkg: cp -a mkextunpack kextstat /usr/sbin #kextcache
