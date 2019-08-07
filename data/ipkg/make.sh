pkg:extract
cd ipkg*
for diff in "${PKG_WORK}"/files/{palm-pkg-remove-warn,!(palm-pkg-remove-warn)}.patch; do
    echo "patching with ${diff}..."
    patch -p1 <"${diff}"
done
pkg:patch
pkg:configure
make
pkg:install
