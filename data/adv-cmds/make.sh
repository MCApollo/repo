pkg:setup
set -x
"${PKG_TARG}-gcc" -O2 ${PKG_MCPU} -DPLATFORM_iPhoneOS -o tabs/tabs tabs/*.c -lncurses 
"${PKG_TARG}-g++" -O2 ${PKG_MCPU} -DPLATFORM_iPhoneOS -o locale/locale locale/*.cc
for tproj in finger last lsvfs cap_mkdb; do
    echo "${tproj}"
    "${PKG_TARG}-gcc" -O2 ${PKG_MCPU} -DPLATFORM_iPhoneOS -o "${tproj}/${tproj}" "${tproj}"/*.c -D'__FBSDID(x)='
done
set +x
pkg: mkdir -p /bin /usr/bin
pkg: cp -a cap_mkdb/cap_mkdb finger/finger last/last locale/locale lsvfs/lsvfs tabs/tabs /usr/bin
