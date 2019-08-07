pkg:extract
pkg: mkdir -p /usr/share /usr/bin
pkg: cp -a * /usr/share/msf3
pkg: "${PKG_TARG}-gcc" -o /usr/share/msf3/data/templates/template_armle_darwin.bin /usr/share/msf3/data/templates/template.c
ln -s /usr/share/msf3/msfcli "${PKG_DEST}"/usr/bin/msfcli
ln -s /usr/share/msf3/msfconsole "${PKG_DEST}"/usr/bin/msfconsole
ln -s /usr/share/msf3/msfd "${PKG_DEST}"/usr/bin/msfd
ln -s /usr/share/msf3/msfelfscan "${PKG_DEST}"/usr/bin/msfelfscan
ln -s /usr/share/msf3/msfencode "${PKG_DEST}"/usr/bin/msfencode
ln -s /usr/share/msf3/msfgui "${PKG_DEST}"/usr/bin/msfgui
ln -s /usr/share/msf3/msfmachscan "${PKG_DEST}"/usr/bin/msfmachscan
ln -s /usr/share/msf3/msfopcode "${PKG_DEST}"/usr/bin/msfopcode
ln -s /usr/share/msf3/msfpayload "${PKG_DEST}"/usr/bin/msfpayload
ln -s /usr/share/msf3/msfpescan "${PKG_DEST}"/usr/bin/msfpescan
ln -s /usr/share/msf3/msfrpc "${PKG_DEST}"/usr/bin/msfperpc
ln -s /usr/share/msf3/msfrpcd "${PKG_DEST}"/usr/bin/msfperpcd
ln -s /usr/share/msf3/msfweb "${PKG_DEST}"/usr/bin/msfweb
