pkg:setup
# Host
./configure --prefix=$PWD/host --disable-shared --enable-static
make -j8 install
make distclean
# Target
pkg:configure 
pkg:install 
# Dict install.
export PATH="${PWD}/host/bin:${PATH}"
mkdir dict; cd dict
for x in ${PKG_DATA}/dict/*; do tar xf ${x}; done
for dir in *; do
   pushd $dir
   x=$(echo "${PKG_DEST}${PKG_TAPF}"/lib/aspell-*)
   sed -i "s|\$dictdir|${x}|" configure
   sed -i "s|\$datadir|${x}|" configure
   ./configure --vars ASPELL=$(which aspell) PREZIP=$(which prezip)
   make install
   popd
done
