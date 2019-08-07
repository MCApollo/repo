pkg:setup
pkg:configure ac_cv_have_abstract_sockets=no --without-x --with-dbus-user=daemon
make
pkg:install
