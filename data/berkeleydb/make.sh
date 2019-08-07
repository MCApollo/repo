pkg:setup
cd dist
rm -f config.sub
cp ${PKG_BASE}/config.sub .
./s_config
cd ../build_unix
PKG_CONF=../dist/configure pkg:configure --with-mutex=Darwin/_spin_lock_try
make -j8
pkg:install
