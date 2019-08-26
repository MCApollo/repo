pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules daq_cv_libpcap_version_1x=yes
make	# on purpose
pkg:install 
