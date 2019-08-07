pkg: mkdir -p /usr
cp -a "$(PKG_DEST_ _apr)"/* "${PKG_DEST}"
pkg: rm -rf /usr/lib
pkg: rmdir --ignore-fail-on-non-empty /usr
