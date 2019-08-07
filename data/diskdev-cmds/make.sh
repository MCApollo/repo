shopt -s extglob
pkg:setup

cd disklib
rm -f mntopts.h getmntopts.c
${PKG_TARG}-gcc -fno-common -c *.c
${PKG_TARG}-ar -r libdisk.a *.o
cd ..

for tproj in !(fstyp|fsck_hfs|fuser|mount_portal|mount_swapfs|mount_umap|newfs_hfs_debug).tproj; do
    tproj=$(basename "${tproj}" .tproj)
    echo ${tproj}

    extra=

    if [[ ${tproj} = restore ]]; then
        extra="${extra} -DRRESTORE"
    fi

    if [[ ${tproj} = mount_cd9660 || ${tproj} = mount_hfs ]]; then
        extra="${extra} -framework IOKit"
    fi

    if [[ ${tproj} = mount_cd9660 || ${tproj} = mount_hfs || ${tproj} = newfs_hfs ]]; then
        extra="${extra} -framework CoreFoundation"
    fi

    ${PKG_TARG}-gcc -Idisklib -o "${tproj}" $(find "${tproj}.tproj" -name '*.c') disklib/libdisk.a -lutil ${extra}
done

cd fstyp.tproj
for c in *.c; do
    bin=../$(basename "${c}" .c)
    ${PKG_TARG}-gcc -o "${bin}" "${c}"
done
cd ..

chmod u+s umount quota

pkg: mkdir -p /usr/bin /usr/libexec /usr/sbin /sbin

# XXX: mt ufs
pkg: cp -a quota /usr/bin
pkg: cp -a dev_mkdb edquota fdisk quotaon repquota vsdbutil /usr/sbin
pkg: cp -a vndevice /usr/libexec
pkg: cp -a quotacheck umount @(fstyp|newfs)?(_*([a-z0-9])) @(mount_*([a-z0-9])) /sbin
