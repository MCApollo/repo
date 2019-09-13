pkg:extract

_VERSION="$(cat ${PKG_DATA}/_metadata/version)"
_INSTALL="${PKG_TAPF}/openjdk-${_VERSION}"

target_args=(
'--enable-option-checking=fatal'
"--openjdk-target=${PKG_TARG}"
'--disable-warnings-as-errors'
'--enable-headless-only'
'--with-jdk-variant=normal'
'--with-jvm-variants=zero'
'--disable-hotspot-gtest'
'--disable-precompiled-headers'
"--with-cups-include=${PKG_WORK}/cups"
"--with-sysroot=${PKG_ROOT}"
'--with-debug-level=release'
'--enable-unlimited-crypto'
# Repo info (Remove me for eluc.):
'--with-vendor-name=Athena'
'--with-vendor-url=MCApollo@protonmail.com'
'--with-vendor-bug-url=None'
'--with-vendor-vm-bug-url=None'
"--with-version-build=${_VERSION}"
'--with-version-pre=""'
'--with-version-opt=""'
)

unset IPHONEOS_DEPLOYMENT_TARGET
# Build for host.
cd openjdk-*
chmod +x ./configure 
if [[ -z "${_USE_JDK}" ]]; then
./configure --with-jvm-variants=client	|| \
	(
	echo "If you're missing java or dependencies try:"
	echo "	brew tap caskroom/versions"
	echo "	brew update"
	echo "	brew cask install adoptopenjdk11"
	echo "Or brew install libtiff, libffi, libpng, etc."
	exit 1
	)
env -i PATH=$PATH make JOBS=2 LOG=info  # => env vars causes errors.
# Build for target.
JDK=$(realpath build/*)
else
# Debug variable:
JDK="${_USE_JDK}"
fi
pkg:patch
rm -rf build/.configure-support
./configure ${target_args[@]} --with-build-jdk="${JDK}/jdk" --with-boot-jdk="${JDK}/jdk"	\
	--with-extra-ldflags="-framework Foundation" --with-extra-cflags="-D_DARWIN_FEATURE_64_BIT_INODE=1 -DDEFAULT_LIBPATH=\"/lib:/usr/lib:/usr/local/lib:${PKG_TAPF}/lib\" "
cd build/macosx-aarch64-*
#  Hacky way to switch to the custom target- avoid some macosx only things.
sed	-e "s|OPENJDK_TARGET_OS:=macosx|OPENJDK_TARGET_OS:=ios|"			\
	-e "s|OPENJDK_TARGET_OS_ENV:=macosx|OPENJDK_TARGET_OS_ENV:=ios|"		\
	-e "s|OPENJDK_TARGET_OS_UPPERCASE:=IOS|OPENJDK_TARGET_OS_UPPERCASE:=IOS|"	\
	-i spec.gmk
make images JOBS=2 LOG=info COMPRESS_JARS=true
# Install
pkg: mkdir -p "${_INSTALL}"
pkg: mkdir -p "${PKG_TAPF}"/bin
cp -Rv images/jdk/* "${PKG_DEST}/${_INSTALL}"
# Install cleanup
rm -rf $(find "${PKG_DEST}/${_INSTALL}" -iname '*.dSYM')
ln -rs "${PKG_DEST}/${_INSTALL}"/bin/* "${PKG_DEST}/${PKG_TAPF}"/bin/
rm -rf "${PKG_DEST}/${_INSTALL}"/{demo,legal,man}
# Reduce filesize.
rm "${PKG_DEST}/${_INSTALL}"/bin/jconsole
rm "${PKG_DEST}/${_INSTALL}"/lib/src.zip
