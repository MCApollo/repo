namespace android {
	namespace build {
		std::string GetBuildNumber() {
#if defined(ADB_VERSION)
			return ADB_VERSION;
#elif defined(FASTBOOT_VERSION)
			return FASTBOOT_VERSION;
#else
			return 0;
#endif
		}
	}
}
