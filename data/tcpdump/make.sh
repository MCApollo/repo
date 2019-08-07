pkg:setup
cp "$(PKG_DEST_ libpcap)/usr/bin/pcap-config" .
sed -ie "s|prefix=.*|prefix=$(PKG_DEST_ libpcap)/usr|" pcap-config
Xprefix="$(PKG_DEST_ openssl)/usr" pkg:configure ac_cv_header_net_pfvar_h=no ac_cv_path_ac_pt_PCAP_CONFIG="./pcap-config"
make
pkg:install
