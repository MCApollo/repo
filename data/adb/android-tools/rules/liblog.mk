# liblog
# =========================================================

LIBLOG_ARCHIVE := obj/liblog/liblog.a

LIBLOG_CFLAGS := \
    -DFAKE_LOG_DEVICE=1 \
    -DLIBLOG_LOG_TAG=1006 \
    -DSNET_EVENT_LOG_TAG=1397638484 \
    -fvisibility=hidden \
    -I$(srcdir)/core/include \
    -I$(srcdir)/core/liblog/include \
    -I$(srcdir)/include \

LIBLOG_CXXFLAGS := \
    -D_LIBCPP_HAS_NO_ATOMIC_HEADER \
    -DFAKE_LOG_DEVICE=1 \
    -DLIBLOG_LOG_TAG=1006 \
    -DSNET_EVENT_LOG_TAG=1397638484 \
    -fvisibility=hidden \
    -I$(srcdir)/core/include \
    -I$(srcdir)/core/liblog/include \
    -I$(srcdir)/include \

LIBLOG_SRC_FILES := \
    config_read.cpp \
    config_write.cpp \
    fake_log_device.cpp \
    fake_writer.cpp \
    log_event_list.cpp \
    log_event_write.cpp \
    logger_lock.cpp \
    logger_name.cpp \
    logger_read.cpp \
    logger_write.cpp \
    logprint.cpp \
    stderr_write.cpp \

LIBLOG_C_OBJ_FILES := \
    $(patsubst %.c,obj/liblog/%.o,$(filter %.c,$(LIBLOG_SRC_FILES)))

LIBLOG_CXX_OBJ_FILES := \
    $(patsubst %.cpp,obj/liblog/%.o,$(filter %.cpp,$(LIBLOG_SRC_FILES)))

DIRS += $(dir $(LIBLOG_C_OBJ_FILES) $(LIBLOG_CXX_OBJ_FILES))

liblog: $(LIBLOG_ARCHIVE)

$(LIBLOG_ARCHIVE): $(LIBLOG_C_OBJ_FILES) $(LIBLOG_CXX_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBLOG_C_OBJ_FILES): obj/liblog/%.o: $(srcdir)/core/liblog/%.c | dirs
	$(CC) $(CFLAGS) $(LIBLOG_CFLAGS) -c -o $@ $^

$(LIBLOG_CXX_OBJ_FILES): obj/liblog/%.o: $(srcdir)/core/liblog/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBLOG_CXXFLAGS) -c -o $@ $^
