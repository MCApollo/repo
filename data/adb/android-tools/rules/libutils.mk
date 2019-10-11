# libutils
# =========================================================

LIBUTILS_ARCHIVE := obj/libutils/libutils.a

LIBUTILS_CXXFLAGS := \
    -fvisibility=protected \
    -I$(srcdir)/core/base/include \
    -I$(srcdir)/core/include \
    -I$(srcdir)/core/libprocessgroup/include \
    -I$(srcdir)/include \
    -include limits.h \

LIBUTILS_SRC_FILES := \
    FileMap.cpp \
    JenkinsHash.cpp \
    NativeHandle.cpp \
    Printer.cpp \
    PropertyMap.cpp \
    RefBase.cpp \
    SharedBuffer.cpp \
    StopWatch.cpp \
    StrongPointer.cpp \
    SystemClock.cpp \
    Threads.cpp \
    Timers.cpp \
    Tokenizer.cpp \
    Unicode.cpp \
    misc.cpp \

LIBUTILS_C_OBJ_FILES := \
    $(patsubst %.c,obj/libutils/%.o,$(filter %.c,$(LIBUTILS_SRC_FILES)))

LIBUTILS_CXX_OBJ_FILES := \
    $(patsubst %.cpp,obj/libutils/%.o,$(filter %.cpp,$(LIBUTILS_SRC_FILES)))

DIRS += $(dir $(LIBUTILS_C_OBJ_FILES) $(LIBUTILS_CXX_OBJ_FILES))

libutils: $(LIBUTILS_ARCHIVE)

$(LIBUTILS_ARCHIVE): $(LIBUTILS_C_OBJ_FILES) $(LIBUTILS_CXX_OBJ_FILES) | dirs
	$(AR) rcs $@ $^

$(LIBUTILS_C_OBJ_FILES): obj/libutils/%.o: $(srcdir)/core/libutils/%.c | dirs
	$(CC) $(CFLAGS) $(LIBUTILS_CFLAGS) -c -o $@ $^

$(LIBUTILS_CXX_OBJ_FILES): obj/libutils/%.o: $(srcdir)/core/libutils/%.cpp | dirs
	$(CXX) $(CXXFLAGS) $(LIBUTILS_CXXFLAGS) -c -o $@ $^
