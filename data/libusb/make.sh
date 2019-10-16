pkg:setup
pkg:configure
pkg:install 

# Create symlink for libusb/libusb.h
shopt -s extglob
ln -rs "${PKG_DEST}/${PKG_TAPF}"/include/libusb-* "${PKG_DEST}/${PKG_TAPF}"/include/libusb
