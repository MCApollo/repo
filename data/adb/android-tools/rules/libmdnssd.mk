# libmdnssd
# =========================================================

LIBMDNSSD_ARCHIVE := obj/libmdnssd/libmdnssd.a

LIBMDNSSD_CFLAGS := \
    -D_GNU_SOURCE \
    -DHAVE_IPV6 \
    -no-cpp-precomp

LIBMDNSSD_SRC_FILES := \
    mDNSShared/dnssd_clientlib.c \
    mDNSShared/dnssd_clientstub.c \
    mDNSShared/dnssd_ipc.c \

LIBMDNSSD_C_OBJ_FILES := \
    $(patsubst %.c,obj/libmdnssd/%.o,$(filter %.c,$(LIBMDNSSD_SRC_FILES)))

LIBMDNSSD_CXX_OBJ_FILES := \
    $(patsubst %.cpp,obj/libmdnssd/%.o,$(filter %.cpp,$(LIBMDNSSD_SRC_FILES)))

DIRS += $(dir $(LIBMDNSSD_C_OBJ_FILES) $(LIBMDNSSD_CXX_OBJ_FILES))

libmdnssd: $(LIBMDNSSD_ARCHIVE)

$(LIBMDNSSD_ARCHIVE): $(LIBMDNSSD_C_OBJ_FILES) $(LIBMDNSSD_CXX_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBMDNSSD_C_OBJ_FILES): obj/libmdnssd/%.o: $(srcdir)/mdnsresponder/%.c | dirs
	$(CC) $(CFLAGS) $(LIBMDNSSD_CFLAGS) -c -o $@ $^

$(LIBMDNSSD_CXX_OBJ_FILES): obj/libmdnssd/%.o: $(srcdir)/mdnsresponder/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBMDNSSD_CXXFLAGS) -c -o $@ $^
