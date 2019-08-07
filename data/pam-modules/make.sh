pkg:setup

pkg: mkdir -p /usr/lib/pam

for module in launchd unix uwtmp; do
    echo "${module}"
    "${PKG_TARG}-gcc" -shared -o "pam_${module}.so" "pam_${module}"/*.c -lpam -I"${PKG_DATA}" || true
    pkg: cp -a "pam_${module}.so" /usr/lib/pam
done
