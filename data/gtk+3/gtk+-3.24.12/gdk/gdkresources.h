#ifndef __RESOURCE__gdk_H__
#define __RESOURCE__gdk_H__

#include <gio/gio.h>

extern GResource *_gdk_get_resource (void);

extern void _gdk_register_resource (void);
extern void _gdk_unregister_resource (void);

#endif
