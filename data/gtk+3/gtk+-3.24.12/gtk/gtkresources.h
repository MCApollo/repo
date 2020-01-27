#ifndef __RESOURCE__gtk_H__
#define __RESOURCE__gtk_H__

#include <gio/gio.h>

extern GResource *_gtk_get_resource (void);

extern void _gtk_register_resource (void);
extern void _gtk_unregister_resource (void);

#endif
