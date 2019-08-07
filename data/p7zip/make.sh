pkg:setup
mv -f makefile.macosx_gcc_64bits makefile.machine
make all2
make install DEST_DIR="${PKG_DEST}" DEST_HOME="/usr"
