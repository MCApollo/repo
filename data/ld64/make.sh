pkg:setup
pkg:make
pkg:install
pkg: mv /usr/bin/ld64 /usr/bin/ld64_
pkg: ln -s ld64 /usr/bin/ld
pkg: "${PKG_TARG}-gcc" %/wrapper.c -o /usr/bin/ld64
if [[ -f "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/entitlement.xml" ]]; then
  pkg: mkdir -p /usr/share/ldid
  cp "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/entitlement.xml" "${PKG_DEST}/usr/share/ldid/entitlements.xml"
fi
