#ifndef	_shared_dns_info_user_
#define	_shared_dns_info_user_

/* Module shared_dns_info */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry 	*function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	shared_dns_info_MSG_COUNT
#define	shared_dns_info_MSG_COUNT	2
#endif	/* shared_dns_info_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include "shared_dns_info_types.h"

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
__BEGIN_DECLS


/* Routine shared_dns_infoGet */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t shared_dns_infoGet
(
	mach_port_t server,
	dnsDataOut_t *data,
	mach_msg_type_number_t *dataCnt
);

/* Routine shared_dns_infoSet */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t shared_dns_infoSet
(
	mach_port_t server,
	dnsData_t data,
	mach_msg_type_number_t dataCnt
);

__END_DECLS

/********************** Caution **************************/
/* The following data types should be used to calculate  */
/* maximum message sizes only. The actual message may be */
/* smaller, and the position of the arguments within the */
/* message layout may vary from what is presented here.  */
/* For example, if any of the arguments are variable-    */
/* sized, and less than the maximum is sent, the data    */
/* will be packed tight in the actual message to reduce  */
/* the presence of holes.                                */
/********************** Caution **************************/

/* typedefs for all requests */

#ifndef __Request__shared_dns_info_subsystem__defined
#define __Request__shared_dns_info_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__shared_dns_infoGet_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
	} __Request__shared_dns_infoSet_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__shared_dns_info_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__shared_dns_info_subsystem__defined
#define __RequestUnion__shared_dns_info_subsystem__defined
union __RequestUnion__shared_dns_info_subsystem {
	__Request__shared_dns_infoGet_t Request_shared_dns_infoGet;
	__Request__shared_dns_infoSet_t Request_shared_dns_infoSet;
};
#endif /* !__RequestUnion__shared_dns_info_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__shared_dns_info_subsystem__defined
#define __Reply__shared_dns_info_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
	} __Reply__shared_dns_infoGet_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__shared_dns_infoSet_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__shared_dns_info_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__shared_dns_info_subsystem__defined
#define __ReplyUnion__shared_dns_info_subsystem__defined
union __ReplyUnion__shared_dns_info_subsystem {
	__Reply__shared_dns_infoGet_t Reply_shared_dns_infoGet;
	__Reply__shared_dns_infoSet_t Reply_shared_dns_infoSet;
};
#endif /* !__RequestUnion__shared_dns_info_subsystem__defined */

#ifndef subsystem_to_name_map_shared_dns_info
#define subsystem_to_name_map_shared_dns_info \
    { "shared_dns_infoGet", 21000 },\
    { "shared_dns_infoSet", 21001 }
#endif

#ifdef __AfterMigUserHeader
__AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#endif	 /* _shared_dns_info_user_ */
