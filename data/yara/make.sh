pkg:setup
./bootstrap.sh
pkg:configure --disable-silent-rules --disable-dependency-tracking  --enable-dotnet --enable-cuckoo --enable-magic --enable-macho --enable-dex --with-crypto
pkg:install 