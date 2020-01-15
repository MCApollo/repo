pkg:extract
export CFLAGS="-I${PKG_DEST}/${PKG_TAPF}/include"
export LDFLAGS="-L${PKG_DEST}/${PKG_TAPF}/lib"

pkg: mkdir -p ${PKG_TAPF}/lib/pkgconfig
for dir in $(grep -v '^#' ${PKG_DATA}/app-7.md5 | awk '{print $2}'); do
    dir=${dir%.tar.bz2}
    dir=${dir%.tar.xz}
    opt=
    pushd ${dir}
    case ${dir} in
     luit-[0-9]* ) 
         sed -i -e "/D_XOPEN/s/5/6/" configure;
     ;;
    esac
    cp -f ${PKG_BASE}/util/config.sub . || :
    pkg:configure --enable-malloc0returnsnull PKG_CONFIG="${PKG_DATA}/pkg-config.sh" ${opt}
    make -j4
    pkg:install
    ln -rsf ${PKG_DEST}/${PKG_TAPF}/share/pkgconfig/*.pc ${PKG_DEST}/${PKG_TAPF}/lib/pkgconfig/ || :
    popd
done
