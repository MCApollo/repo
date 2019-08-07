pkg:setup
cp ${PKG_BASE}/config.sub .
pkg:configure
pkg:make
pkg:install
# For if we start including docs
#pkg: mkdir -p /usr/share/doc/dns2tcp/examples
#pkg: cp README /usr/share/doc/dns2tcp/
#pkg: cp client/dns2tcprc server/dns2tcpdrc /usr/share/doc/dns2tcp/examples/
