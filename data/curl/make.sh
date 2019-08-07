pkg:setup
pkg:configure ac_cv_file___dev_urandom_=yes --with-ca-bundle=/etc/ssl/certs/cacert.pem
pkg:make -j8
pkg:install
