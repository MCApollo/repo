pkg:setup
export ARCH=$(echo ${PKG_TARG} | sed -e s/'-.*'//)
sed -i 's/$pkg_version/"$pkg_version"/' configure # for pkg-config.sh
sed -i 's/aom >= 1.0.0/aom >= 0.1.0/' configure # aom version is wrong.
./configure --arch=${ARCH} --pkg-config=pkg-config.sh --prefix=${PKG_TAPF} --enable-cross-compile --cross-prefix="${PKG_TARG}-" --target-os=darwin --disable-static --enable-static --enable-pthreads --enable-version3 --enable-avresample --enable-ffplay --enable-gnutls --enable-gpl --enable-libaom --enable-libbluray --enable-libmp3lame --enable-libopus --enable-librubberband --enable-libsnappy --enable-libtesseract --enable-libtheora --enable-libvidstab --enable-libvorbis --enable-libvpx --enable-libx264 --enable-libx265 --enable-libxvid --enable-lzma --enable-libfontconfig --enable-libfreetype --enable-frei0r --enable-libass --enable-libopencore-amrnb --enable-libopencore-amrwb --enable-libopenjpeg --enable-librtmp --enable-libspeex --enable-libsoxr --enable-videotoolbox --disable-libjack --disable-indev=jack --enable-shared --disable-static

make -j4
pkg:install

make alltools 
for exe in $(find tools/ -type f \( -perm -u=x -o -perm -g=x -o -perm -o=x \) -exec test -x {} \; -print); do
    case $(file ${exe}) in
        *Mach-O*) cp ${exe} ${PKG_DEST}/${PKG_TAPF}/bin ;;
    esac
done
