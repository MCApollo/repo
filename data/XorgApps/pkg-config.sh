#!/bin/bash
declare -a args
declare -a pkgs
unset dbpf
export PKG_TAPF=$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix")

while [[ $# -ne 0 ]]; do case "$1" in
    (--version)
	echo "0.29.1"
	exit 0
    ;;
    (--atleast-pkgconfig-version)
        exec pkg-config "$1" "$2"
    ;;

    (--cflags|--libs|--libs-only-l|--libs-only-L|--cflags-only-I|--variable=*)
        dbpf=
        args[${#args[@]}]=$1
    ;;

    (--errors-to-stdout|--exists|--modversion|--print-errors|--short-errors|--uninstalled|--debug)
        args[${#args[@]}]=$1
    ;;

    (--atleast-version|--exact-version|--max-version)
        args[${#args[@]}]=$1
        args[${#args[@]}]=$2
        shift
    ;;

		(--atleast-version=*)
        args[${#args[@]}]=--atleast-version
				args[${#args[@]}]=$(echo $1 | cut -d = -f 2)
    ;;

    (--*)
        echo "unknown pkg-config option $1" 1>&2
        exit 1
    ;;

    (*)
        pkgs[${#pkgs[@]}]=$1
    ;;
esac; shift; done

if [[ ${dbpf+@} ]]; then
    source "${PKG_BASE}/lib/folders.sh"
fi

function join_by { local IFS="$1"; shift; echo "$*"; }
declare -a PKG_SEARCH_PATH
for dep in $(find -L "${PKG_DATA}"/_metadata -name '*.dep'; echo "_metadata/$(basename ${PKG_DATA}).dep"); do
    DEP_NAME=$(basename "${dep}" .dep)
    DEP_DEST=$(PKG_DEST_ "${DEP_NAME}")
#    echo @@@ "$DEP_NAME" "$DEP_DEST" 2>&1
    PKG_SEARCH_PATH+=( $(find "${DEP_DEST}" -type d -name pkgconfig | head -n 1) )
done
export PKG_CONFIG_PATH=$(join_by : ${PKG_SEARCH_PATH[*]})

outs=
for pkg in "${pkgs[@]}"; do
    declare -a pkgspec
    pkgspec=( ${pkg} )
    args_=("${args[@]}")
    destdir=

    # Locate the file in the search path and get the destdir.
    destdir=$(find ${PKG_SEARCH_PATH[@]} -name ${pkg}.pc); destdir=${destdir%%${PKG_TAPF}*}

    out=$(pkg-config "${args_[@]}" "${pkg}") || exit $?
    # Replace out prefix with $destdir/prefix
    out=${out//${PKG_TAPF}/${destdir}/${PKG_TAPF}}
    outs+=\ ${out}
done

echo "${out#\ }"
