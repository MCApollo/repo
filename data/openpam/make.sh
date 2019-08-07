pkg:setup

pkg: mkdir -p /etc/pam.d
for pam in pam.d/!(*.serverinstall); do
    echo ${pam}
    # XXX: fix pam_launchd
    sed -re '/^#|.*pam_(deny|nologin|permit|rootok|securetty|unix|uwtmp|wheel).so/ ! s/^/#/; ' "${pam}" >"${PKG_DEST}/etc/${pam}"
done

cd openpam
touch NEWS AUTHORS ChangeLog
autoreconf -f -i
pkg:configure --enable-fakeroot="${PKG_DEST}" --enable-read-both-confs --enable-sconfigdir=/etc/pam --enable-securedir=/usr/lib/pam --enable-giant-libpam --disable-libcrack ac_cv_c_bigendian=no

CPATH=$(pwd):$CPATH
make CC="${PKG_TARG}-gcc" AR="${PKG_TARG}-ar" LD="${PKG_TARG}-ld" RANLIB="${PKG_TARG}-ranlib"
pkg:install
