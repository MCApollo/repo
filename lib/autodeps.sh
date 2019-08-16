#!/bin/bash
export PATH=${PKG_BASE}/util:$PATH
declare -a PKG_DPKG_DEPS
declare -a PKG_MISSING_DEPS
for dep in "${PKG_DEPS[@]}"; do
    # XXX: bother dealing with weird arguments?
    #DEPNAME=$(basename "${dep}" .dep)
    if  [ ! -z "${dep##_*}" ]; then
        PKG_DPKG_DEPS[${#PKG_DPKG_DEPS[@]}]="${dep}"
    fi
done

if [[ -e ${PKG_DATA}/_metadata/depends ]]; then
    IFS=, read -a DEPENDS < "${PKG_DATA}/_metadata/depends"
    for dep in "${DEPENDS[@]}"; do
        dep="${dep#[[:space:]]}"
        PKG_DPKG_DEPS[${#PKG_DPKG_DEPS[@]}]="${dep%%[[:space:]]*}"
    done
fi

declare -a deps
deps=($(find -L "${PKG_DATA}"/_metadata -name '*.dep' | sed -e 's/^.*\///' -e 's/\.dep$//' | sort -u))

#echo Current Depends: $(IFS=','; echo "${PKG_DPKG_DEPS[*]}" | sed -e 's/,/, /g')
for bin in $(find "${PKG_DEST}" -type f \( -perm -0100 -o -name '*.dylib' -o -name '*.so' \)); do
    case "$(file "${bin}")" in (\
            *': Mach-O fat file with '*([0-9])' architecture' |\
            *': '*(setuid |setgid )'Mach-O 64-bit executable arm64' |\
            *': Mach-O '?(64-bit )'dynamically linked shared library '@(acorn|arm64) |\
            *': Mach-O '?(64-bit )'bundle '@(acorn|arm64) |\
            *': '*(setuid |setgid )'Mach-O executable acorn' \
        )
        ;; 
        (*) continue
        ;;
    esac

    for dylib in $(otool  -L "${bin}"  | grep -E '^\s' | sed -e 's/^\s*//' -e 's/ .*//'); do
        if [ "${dylib}" = "${bin#${PKG_DEST}}" ]; then continue; fi
        shopt -u nullglob

        DEP_PKG="$(ls "${PKG_BASE}"/dest/${PKG_ARCH}/${PKG_CFTARG}/@(${PKG_NAME}|$(IFS='|'; echo "${PKG_DPKG_DEPS[*]}"'|'"${PKG_MISSING_DEPS[*]}"))/"$dylib" 2>/dev/null | sed -e "s|.*/${PKG_ARCH}/${PKG_CFTARG}//*||" -e 's|/.*||' | grep -v '^_')"
        if [ -z "${DEP_PKG}" ]; then
            DEP_PKG="$(ls "${PKG_BASE}"/dest/${PKG_ARCH}/${PKG_CFTARG}/@($(IFS='|'; echo "${deps[*]}"))/"$dylib" 2>/dev/null | sed -e "s|.*/${PKG_ARCH}/${PKG_CFTARG}//*||" -e 's|/.*||')"
            if [ -z "${DEP_PKG}" ]; then continue; fi
            if [ -z "${DEB_PKG%_*}" ]; then
                DEP_PKG=$(ls "${PKG_BASE}"/dest/${PKG_ARCH}/${PKG_CFTARG}/*/"$dylib" 2>/dev/null | sed -e "s|.*/${PKG_ARCH}/${PKG_CFTARG}//*||" -e 's|/.*||' | grep -v '^_')
            fi
            if [ "${DEP_PKG#*[[:space:]]}" != "${DEP_PKG}" ]; then
                echo "Error: found multiple possible matches for ${dylib}: $(echo "${DEP_PKG}" | tr '\n' ',' | sed -e 's/,\s*$//')" >&2
                echo "Please add one as a depend or clean up old packages from dest/" >&2
                exit 1
            fi
            if [ ! -z "${DEP_PKG}" ]; then
                PKG_MISSING_DEPS[${#PKG_MISSING_DEPS[@]}]="${DEP_PKG}"
                if [ ! -e "${PKG_DATA}"/_metadata/autodeps ]; then
                    echo WARNING: found dependency upon ${DEP_PKG} which is not yet depended upon >&2
                fi
            fi
        fi
        shopt -s nullglob
    done 
done
if [ ${#PKG_MISSING_DEPS[@]} -gt 0 ]; then
    if [ ! -e "${PKG_DATA}"/_metadata/autodeps ]; then
        echo WARNING: Missing Depends: $(IFS=','; echo "${PKG_MISSING_DEPS[*]}" | sed -e 's/,/, /g') >&2
        echo WARNING: Either enable autodeps or add to depends >&2
    else
        PKG_DEPS=("${PKG_DEPS[@]}" "${PKG_MISSING_DEPS[*]}")
    fi
fi
#echo Final Depends: $(IFS=','; echo "${PKG_DPKG_DEPS[*]}" | sed -e 's/,/, /g')
