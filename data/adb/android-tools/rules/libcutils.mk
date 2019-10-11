# libcutils
# =========================================================

LIBCUTILS_ARCHIVE := obj/libcutils/libcutils.a

LIBCUTILS_CFLAGS := \
    -include uchar.h \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/libcutils/include \
    -I$(srcdir)/core/include \
    -I$(srcdir)/include \

LIBCUTILS_CXXFLAGS := \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/libcutils/include \
    -I$(srcdir)/core/include \
    -I$(srcdir)/include \
    -include sys/select.h \
    -Wexit-time-destructors \

LIBCUTILS_SRC_FILES := \
    ashmem-host.cpp \
    canned_fs_config.cpp \
    config_utils.cpp \
    fs.cpp \
    fs_config.cpp \
    hashmap.cpp \
    iosched_policy.cpp \
    load_file.cpp \
    multiuser.cpp \
    native_handle.cpp \
    record_stream.cpp \
    socket_inaddr_any_server_unix.cpp \
    socket_local_client_unix.cpp \
    socket_local_server_unix.cpp \
    socket_network_client_unix.cpp \
    sockets.cpp \
    sockets_unix.cpp \
    str_parms.cpp \
    strdup16to8.cpp \
    strdup8to16.cpp \
    threads.cpp \
    trace-host.cpp \

LIBCUTILS_C_OBJ_FILES := \
    $(patsubst %.c,obj/libcutils/%.o,$(filter %.c,$(LIBCUTILS_SRC_FILES)))

LIBCUTILS_CXX_OBJ_FILES := \
    $(patsubst %.cpp,obj/libcutils/%.o,$(filter %.cpp,$(LIBCUTILS_SRC_FILES)))

DIRS += $(dir $(LIBCUTILS_C_OBJ_FILES) $(LIBCUTILS_CXX_OBJ_FILES))

libcutils: $(LIBCUTILS_ARCHIVE)

$(LIBCUTILS_ARCHIVE): $(LIBCUTILS_C_OBJ_FILES) $(LIBCUTILS_CXX_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBCUTILS_C_OBJ_FILES): obj/libcutils/%.o: $(srcdir)/core/libcutils/%.c | dirs
	$(CC) $(CFLAGS) $(LIBCUTILS_CFLAGS) -c -o $@ $^

$(LIBCUTILS_CXX_OBJ_FILES): obj/libcutils/%.o: $(srcdir)/core/libcutils/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBCUTILS_CXXFLAGS) -c -o $@ $^
