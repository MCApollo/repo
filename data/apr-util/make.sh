pkg:setup
APRWORK=("$(PKG_WORK_ _apr)"/*/)
pkg:configure --disable-static --with-apr="${APRWORK}" --with-berkeley-db="$(PKG_DEST_ berkeleydb)/usr"
# WTF configure... I need to fix this
sed -ie 's/db-6.9/db/' Makefile apu-1-config
make -j8
pkg:install
