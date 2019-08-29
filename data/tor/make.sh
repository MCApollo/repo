pkg:setup
pkg:configure --disable-dependency-tracking --disable-silent-rules  --sysconfdir=${PKG_TAPF}/etc	# TODO: Fix use of system lzma, so SDK's version can be used.
pkg:install 
