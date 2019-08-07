pkg:extract
cd *
./configure
make -j8
pkg:patch
CFLAGS='-Wno-format' pkg:configure --disable-ipv6 ac_cv_file__dev_ptmx=yes ac_cv_file__dev_ptc=no ac_cv_have_long_long_format=yes --disable-toolbox-glue
make -j8 
pkg:install
