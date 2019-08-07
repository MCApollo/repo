pkg:setup
autoconf

function pkg_:split {
    size=$1
    data=$2
    half=$(($(wc -l "${data}" | cut -d ' ' -f 1) / size))

    for ((i = 0; i != size; ++i)); do
        tail -n +"$((half * i + 1))" "${data}" | head -n "${half}" >"${data}-$i.c"
    done
}

pkg: cp -a %/cmu_lex_data-{0,1}.c lang/cmulex
pkg_:split 2 lang/cmulex/cmu_lex_data_raw.c
pkg_:split 5 lang/cmu_us_kal/cmu_us_kal_res.c

for ((i = 0; i != 5; ++i)); do
    if [[ $i != 0 ]]; then
        echo 'const unsigned char cmu_us_kal_res_'"${i}"'_[] = {' >>lang/cmu_us_kal/cmu_us_kal_res-"${i}".c
    fi

    echo '#include "cmu_us_kal_res.c-'"${i}"'.c"' >>lang/cmu_us_kal/cmu_us_kal_res-"${i}".c

    if [[ $i != 4 ]]; then
        echo '};' >>lang/cmu_us_kal/cmu_us_kal_res-"${i}".c
    fi
done

pkg:configure
mkdir -p build/arm-darwin/obj/lang/cmu_us_kal16
touch build/arm-darwin/obj/lang/cmu_us_kal16/cmu_us_kal16_res.o

mkdir -p build/arm-darwin/obj/lang/cmulex
mkdir -p build/arm-darwin/obj/lang/cmu_us_kal
touch build/arm-darwin/obj/lang/cmulex/cmu_lex_data.o
touch build/arm-darwin/obj/lang/cmu_us_kal/cmu_us_kal_res.o
make
make install prefix="${PKG_DEST}/usr"
