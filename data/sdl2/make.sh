pkg:setup
CFLAGS="-DNDEBUG -g -O0 -pipe -fPIC -fobjc-arc" \
pkg:configure --disable-shared --enable-static
cp include/SDL_config_iphoneos.h include/SDL_config.h 
make
pkg:install 
