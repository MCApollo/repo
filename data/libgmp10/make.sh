pkg:setup
if [[ "${PKG_CFTARG}" == "1443.00" ]]; then
    pkg:configure --with-libgcrypt-prefix="$(PKG_DEST_ gcrypt)/usr"
else
    pkg:configure --with-libgcrypt-prefix="$(PKG_DEST_ gcrypt)/usr" --disable-assembly
fi
pkg:make -j8
pkg:install
