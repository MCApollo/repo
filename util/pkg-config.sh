#!/bin/bash

#echo 1>&2
#echo ::: "$@" 1>&2

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

    (--errors-to-stdout|--exists|--modversion|--print-errors|--short-errors|--uninstalled|--debug|--static)
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

outs=
for pkg in "${pkgs[@]}"; do
    declare -a pkgspec
    pkgspec=( ${pkg} )
    args_=("${args[@]}")

    if [[ ${dbpf+@} ]]; then
        dest=$(for dep in $(find -L "${PKG_DATA}"/_metadata -name '*.dep'); do
            DEP_NAME=$(basename "${dep}" .dep)
            DEP_DEST=$(PKG_DEST_ "${DEP_NAME}")

            find "${DEP_DEST}" -name "${pkgspec}.pc" -printf "${DEP_DEST}\n"
        done | head -n 1) && args_=(--define-variable=prefix="${dest}/${PKG_TAPF}" "${args_[@]}")
    fi

    echo @@@ pkg-config "${args_[@]}" "${pkg}" 1>&2
    out=$(pkg-config "${args_[@]}" "${pkg}") || exit $?
    #echo "=== ${out}" 1>&2
    outs+=\ ${out}
done

echo "${out#\ }"
