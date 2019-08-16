#!/usr/bin/env bash

function pkg:patch() {
    pkg:libtool_ libtool
    pkg:libtool_ ltmain.sh

    for diff in "${PKG_DATA}"/*.diff; do
        if [[ ${diff} =~ .*/_[^/]*.diff$ ]]; then
            continue;
        fi

        args=$(cat ${diff%.diff}.args 2>/dev/null || true)
        echo "patching with ${diff}..."
        patch ${args:=-p1} <"${diff}"
    done
}
export -f pkg:patch

function pkg:bin() {
    if [[ $# -eq 0 ]]; then
        pushd "${PKG_DEST}/usr/bin"
        set $(ls)
        popd
    fi

    ${FAKEROOT} mkdir -p "${PKG_DEST}/bin"
    for bin in "$@"; do
        ${FAKEROOT} mv -v "${PKG_DEST}/usr/bin/${bin}" "${PKG_DEST}/bin/${bin}"
    done

    ${FAKEROOT} rmdir --ignore-fail-on-non-empty -p "${PKG_DEST}/usr/bin"
}
export -f pkg:bin

function pkg:autoconf() {
    for m4 in $(find -name "*.m4"); do
        patch -F 3 -r/dev/null "${m4}" "${PKG_BASE}/util/libtool.m4.diff" || true
    done

		autoconf
}
export -f pkg:autoconf

function pkg:libtool_() {
    for ltmain in $(find -name "$1"); do
        patch -r/dev/null "${ltmain}" "${PKG_BASE}/util/libtool.diff" || true
    done
}
export -f pkg:libtool_

function pkg:setup() {
    pkg:extract
		if [ -z ""*/ ]; then
			echo "Empty package??"
			exit 1
		fi
    cd */
    pkg:patch
}
export -f pkg:setup

export PKG_CONF=./configure
function pkg:configure() {
    cfg=("${PKG_CONF}" \
        ac_cv_prog_cc_g=no ac_cv_prog_cxx_g=no \
        --build="$(${PKG_BASE}/util/config.guess)" \
        --host="${PKG_TARG}" \
        --enable-static=no \
        --enable-shared=yes \
        --prefix=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix") \
        --localstatedir="/var/cache/${PKG_NAME}" \
        CFLAGS="-O2 ${PKG_MCPU} ${CFLAGS}" \
        CXXFLAGS="-O2 ${PKG_MCPU} ${CXXFLAGS}" \
        "$@")
    echo "${cfg[@]}"
    PKG_CONFIG="$(realpath "${PKG_BASE}/util/pkg-config.sh")" \
    "${cfg[@]}"
}
export -f pkg:configure

function pkg:make() {
    make -j16 CC="${PKG_TARG}-gcc" CXX="${PKG_TARG}-g++" AR="${PKG_TARG}-ar" "$@"
}
export -f pkg:make

function pkg:install() {
    ${FAKEROOT} make install -j16 CC="${PKG_TARG}-gcc" CXX="${PKG_TARG}-g++" AR="${PKG_TARG}-ar" DESTDIR="${PKG_DEST}" "$@"
    # Go die in a horrible fire, libtool
    find "${PKG_DEST}" -name '*.la' -exec rm {} +
}
export -f pkg:install

function pkg:extract() {
    for tgz in "${PKG_DATA}"/*.{tar.{gz,xz,bz2,lz},tgz}; do
        tar -xf "${tgz}"
    done

    for zip in "${PKG_DATA}"/*.zip; do
        unzip "${zip}"
    done
}
export -f pkg:extract

function pkg:usrbin() {
    pkg: mkdir -p /usr/bin
    pkg: cp -a "$@" /usr/bin
}
export -f pkg:usrbin

function rmdir_() {
    if [[ -d "$1" ]]; then
        rmdir --ignore-fail-on-non-empty "$1"
    fi
}
export -f rmdir_