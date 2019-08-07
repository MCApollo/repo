LIBDIR="$("$(PKG_WORK_ perl)"/perl-5*/miniperl_top -e 'use Config; print $Config{vendorlib};')"
pkg: mkdir -p "/${LIBDIR}"
cp -a "$(PKG_DEST_ _dpkg)/${LIBDIR}" "${PKG_DEST}/${LIBDIR}"
pushd "$(PKG_DEST_ _dpkg)/"
grep -Erl '#!\s?/usr/bin/perl' . | while read -r line; do
    dir=$(dirname $line)
    pkg: mkdir -p "/${dir}"
    pkg: cp -a "$line" "/${dir}"
done
popd
pkg: rm -rf /{usr,var}/lib{,exec}/dpkg/methods
