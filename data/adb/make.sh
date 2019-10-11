pkg:setup
version="$(cat ${PKG_DATA}/_metadata/version)"
pkg:install PREFIX=${PKG_TAPF} adb_version="${version}" fastboot_version="${version}"
