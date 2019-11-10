pkg:setup
pkg:configure --disable-debug --disable-dependency-tracking  --sysconfdir=${PKG_TAPF}/etc --enable-color --enable-extra --enable-multibuffer --enable-nanorc --enable-utf8
pkg:install 

pkg: mkdir -p ${PKG_TAPF}/etc/
cat << EOF > ${PKG_DEST}/${PKG_TAPF}/etc/nanorc
set autoindent
set constantshow
set fill 72
set historylog
set multibuffer
set positionlog
set quickblank
set suspend
EOF
