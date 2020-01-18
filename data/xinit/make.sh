pkg:setup
pkg:configure --with-xinitdir=${PKG_TAPF}/etc/X11/app-defaults
sed -i "s/mig/${PKG_TARG}-mig/" launchd/privileged_startx/Makefile
pkg:install
