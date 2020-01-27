#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.test_css_style"), aligned (8)))
#else
# define SECTION
#endif

#ifdef _MSC_VER
static const SECTION union { const guint8 data[317]; const double alignment; void * const ptr;}  test_css_style_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0344, 0000, 0000, 0000, 0000, 0000, 0000, 0050, 0007, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 0004, 0000, 0000, 0000, 0006, 0000, 0000, 0000, 
  0006, 0000, 0000, 0000, 0007, 0000, 0000, 0000, 0007, 0000, 0000, 0000, 0214, 0317, 0341, 0030, 
  0003, 0000, 0000, 0000, 0344, 0000, 0000, 0000, 0007, 0000, 0114, 0000, 0354, 0000, 0000, 0000, 
  0360, 0000, 0000, 0000, 0016, 0345, 0303, 0003, 0000, 0000, 0000, 0000, 0360, 0000, 0000, 0000, 
  0006, 0000, 0114, 0000, 0370, 0000, 0000, 0000, 0374, 0000, 0000, 0000, 0113, 0120, 0220, 0013, 
  0005, 0000, 0000, 0000, 0374, 0000, 0000, 0000, 0004, 0000, 0114, 0000, 0000, 0001, 0000, 0000, 
  0004, 0001, 0000, 0000, 0100, 0364, 0277, 0000, 0002, 0000, 0000, 0000, 0004, 0001, 0000, 0000, 
  0004, 0000, 0114, 0000, 0010, 0001, 0000, 0000, 0014, 0001, 0000, 0000, 0151, 0022, 0040, 0141, 
  0006, 0000, 0000, 0000, 0014, 0001, 0000, 0000, 0007, 0000, 0166, 0000, 0030, 0001, 0000, 0000, 
  0050, 0001, 0000, 0000, 0324, 0265, 0002, 0000, 0377, 0377, 0377, 0377, 0050, 0001, 0000, 0000, 
  0001, 0000, 0114, 0000, 0054, 0001, 0000, 0000, 0060, 0001, 0000, 0000, 0214, 0301, 0362, 0100, 
  0001, 0000, 0000, 0000, 0060, 0001, 0000, 0000, 0006, 0000, 0114, 0000, 0070, 0001, 0000, 0000, 
  0074, 0001, 0000, 0000, 0154, 0151, 0142, 0147, 0164, 0153, 0057, 0000, 0001, 0000, 0000, 0000, 
  0164, 0150, 0145, 0155, 0145, 0057, 0000, 0000, 0006, 0000, 0000, 0000, 0157, 0162, 0147, 0057, 
  0003, 0000, 0000, 0000, 0147, 0164, 0153, 0057, 0000, 0000, 0000, 0000, 0147, 0164, 0153, 0056, 
  0143, 0163, 0163, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0000, 0000, 0050, 0165, 0165, 0141, 0171, 0051, 0057, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 
  0105, 0155, 0160, 0164, 0171, 0057, 0000, 0000, 0004, 0000, 0000, 0000
} };
#else /* _MSC_VER */
static const SECTION union { const guint8 data[317]; const double alignment; void * const ptr;}  test_css_style_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\344\000\000\000\000\000\000\050\007\000\000\000"
  "\000\000\000\000\002\000\000\000\004\000\000\000\006\000\000\000"
  "\006\000\000\000\007\000\000\000\007\000\000\000\214\317\341\030"
  "\003\000\000\000\344\000\000\000\007\000\114\000\354\000\000\000"
  "\360\000\000\000\016\345\303\003\000\000\000\000\360\000\000\000"
  "\006\000\114\000\370\000\000\000\374\000\000\000\113\120\220\013"
  "\005\000\000\000\374\000\000\000\004\000\114\000\000\001\000\000"
  "\004\001\000\000\100\364\277\000\002\000\000\000\004\001\000\000"
  "\004\000\114\000\010\001\000\000\014\001\000\000\151\022\040\141"
  "\006\000\000\000\014\001\000\000\007\000\166\000\030\001\000\000"
  "\050\001\000\000\324\265\002\000\377\377\377\377\050\001\000\000"
  "\001\000\114\000\054\001\000\000\060\001\000\000\214\301\362\100"
  "\001\000\000\000\060\001\000\000\006\000\114\000\070\001\000\000"
  "\074\001\000\000\154\151\142\147\164\153\057\000\001\000\000\000"
  "\164\150\145\155\145\057\000\000\006\000\000\000\157\162\147\057"
  "\003\000\000\000\147\164\153\057\000\000\000\000\147\164\153\056"
  "\143\163\163\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\050\165\165\141\171\051\057\000\000\000\002\000\000\000"
  "\105\155\160\164\171\057\000\000\004\000\000\000" };
#endif /* !_MSC_VER */

static GStaticResource static_resource = { test_css_style_resource_data.data, sizeof (test_css_style_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };
extern GResource *test_css_style_get_resource (void);
GResource *test_css_style_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a sane way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for Win32 (x86) and x64 programs, as symbols on Win32 are prefixed
 * with an underscore but symbols on x64 are not.
 */
#ifdef _WIN64
#define G_MSVC_SYMBOL_PREFIX ""
#else
#define G_MSVC_SYMBOL_PREFIX "_"
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
