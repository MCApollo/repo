pkg:setup
pkg:configure --disable-image --with-ssl ac_cv_func_setpgrp_void=yes
# Host hack.
make mktable CC="clang -L $(brew --prefix bdw-gc)/lib" || \
     { echo 'Install libgc: `brew install bdw-gc`' 2>&1; exit 1; }
mv mktable mktable-; make clean
sed -i 's|./mktable|./mktable-|' Makefile

pkg:install 
