shopt -s extglob
pkg:setup

FILES=""
for tproj in !(ping|rtadvd|rarpd|spray).tproj; do
    tproj=$(basename "${tproj}" .tproj)
    echo "${tproj}"
		FILES="${FILES} ${tproj}"
		set -x
    "${PKG_TARG}-gcc" -O2 ${PKG_MCPU} -o "${tproj}" "${tproj}.tproj"/!(ns).c ecnprobe/gmt2local.c -DPRIVATE -DINET6 -DPLATFORM_iPhoneOS -D__APPLE_USE_RFC_3542=1 -DUSE_RFC2292BIS=1 -D__APPLE_API_OBSOLETE=1 -DTARGET_OS_EMBEDDED=1	-Dether_ntohost=_old_ether_ntohost
		set +x
done

echo done, made ${FILES}

pkg: mkdir -p {,/usr}/{,s}bin /usr/libexec

pkg: cp -a kdumpd /usr/libexec
pkg: cp -a ifconfig ip6addrctl netstat ping6 route rtsol /sbin
pkg: cp -a arp ndp traceroute mnc mtest traceroute6 /usr/sbin

ln -s /sbin/ping6 "${PKG_DEST}"/bin
