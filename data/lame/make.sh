pkg:setup
sed -i '/lame_init_old/d' include/libmp3lame.sym
pkg:configure --disable-dependency-tracking --disable-debug  --enable-nasm
pkg:install 
