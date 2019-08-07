pkg:setup
cd source
./autogen.sh
pkg:configure samba_cv_CC_NEGATIVE_ENUM_VALUES=yes --without-cluster-support --disable-swat --without-ldap --with-configdir=/etc/samba --with-privatedir=/etc/samba --with-fhs --without-utmp
pkg:make
pkg:install BIN_PROGS4=
pkg: mkdir /usr/samba

function smb:move() {
    usr=$1
    rex=$2
    pkg: mkdir /usr/samba/"${usr}"
    for bin in "${PKG_DEST}"/usr/"${usr}"/*; do
        bin=${bin##*/}
        if [[ ${bin} =~ ${rex} ]]; then
            pkg: mv /usr/"${usr}"/"${bin}" /usr/samba/"${usr}"
            ln -s /usr/samba/"${usr}"/"${bin}" "${PKG_DEST}"/usr/"${usr}"/"${bin}"
        fi
    done
}

smb:move bin '.*'
smb:move lib '.*\.dylib\.[0-9]'
smb:move sbin '.*'
