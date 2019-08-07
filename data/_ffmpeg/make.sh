pkg:setup
ARCH=$(echo ${PKG_TARG} | sed -e s/'-.*'//)

# Arguments taken from:
# https://github.com/Homebrew/homebrew-core/blob/master/Formula/ffmpeg.rb

# Xz and gnutls included since they are default dependencies.

# WARNING: --enable-gpl and --enable-nonfree can make ffmpeg not legally redistributable.
# --enable-gpl includes code with the gpl license.


./configure --arch=${ARCH} --pkg-config=pkg-config.sh --prefix="$(cat "${PKG_BASE}/arch/${PKG_ARCH}/${PKG_CFTARG}/prefix")" \
    --enable-cross-compile --cross-prefix="${PKG_TARG}-" --target-os=darwin \
    --disable-static --enable-shared --disable-debug --disable-stripping \
    --enable-pthreads --enable-version3 --enable-hardcoded-tables --enable-gnutls \
    --enable-gpl --enable-libmp3lame --enable-libopus --enable-libtheora \
    --enable-libvorbis --enable-libvpx --enable-libx264 --enable-libx265 \
    --enable-libxvid --enable-lzma # --enable-nonfree
make -j16
pkg:install
