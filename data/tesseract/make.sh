pkg:setup
export LIBLEPT_HEADERSDIR="$(PKG_DEST_ leptonica)/${PKG_TAPF}/include/leptonica"
./autogen.sh
pkg:configure  --disable-dependency-tracking --datarootdir=${PKG_TAPF}/share
make
pkg:install  datarootdir=${PKG_TAPF}/share
# Install training data.
cp ${PKG_DATA}/train-data/* ${PKG_DEST}/${PKG_TAPF}/share/tessdata
