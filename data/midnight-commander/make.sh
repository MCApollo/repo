pkg:setup
pkg:configure --disable-debug --disable-dependency-tracking --disable-silent-rules  --without-x --with-screen=slang --enable-vfs-sftp # ac_cv_func_utimensat=no
pkg:install 
