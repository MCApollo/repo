cp -a "$(PKG_DEST_ _dpkg)/." "${PKG_DEST}/"
pkg: rm -rf "$("$(PKG_WORK_ perl)"/perl-5*/miniperl_top -e 'use Config; print $Config{vendorlib};')"
pkg: grep -Erl '#!\s?/usr/bin/perl' / | while read -r line; do
    echo rm -f "${line}"
    rm -f "${line}"
done
pkg: rm -rf /{usr,var}/lib{,exec}/dpkg/methods
pkg: mkdir -p /var/log/dpkg
