#ifndef	_kextmanager_user_
#define	_kextmanager_user_

/* Module kextmanager */

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

#ifndef	kextmanager_MSG_COUNT
#define	kextmanager_MSG_COUNT	12
#endif	/* kextmanager_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <Security/Authorization.h>
#include <IOKit/kext/kextmanager_types.h>
#include <mach/kmod.h>
#include <sys/param.h>

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
__BEGIN_DECLS


/* Routine kextmanager_path_for_bundle_id */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path,
	kext_result_t *kext_result
);

/* Routine kextmanager_create_property_value_array */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_create_property_value_array
(
	mach_port_t server,
	property_key_t prop_key,
	xmlDataOut_t *data,
	mach_msg_type_number_t *dataCnt
);

/* Routine kextmanager_user_did_log_in */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_user_did_log_in
(
	mach_port_t server,
	uint32_t euid,
	AuthorizationExternalForm authref
);

/* Routine kextmanager_user_will_log_out */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_user_will_log_out
(
	mach_port_t server,
	uint32_t euid
);

/* Routine kextmanager_get_logged_in_userid */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_get_logged_in_userid
(
	mach_port_t server,
	uint32_t *euid
);

/* Routine kextmanager_record_nonsecure_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_record_nonsecure_kextload
(
	mach_port_t server,
	xmlDataIn_t load_data,
	mach_msg_type_number_t load_dataCnt
);

/* Routine kextmanager_lock_reboot */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_lock_reboot
(
	mach_port_t server,
	mach_port_t reaper,
	int waitForLock,
	mountpoint_t busyVol,
	int *busyStatus
);

/* Routine kextmanager_lock_volume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_lock_volume
(
	mach_port_t server,
	mach_port_t reaper,
	uuid_t vol_uuid,
	int waitForLock,
	int *lockStatus
);

/* Routine kextmanager_unlock_volume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_unlock_volume
(
	mach_port_t server,
	mach_port_t clientIdent,
	uuid_t vol_uuid,
	int exitStatus
);

/* Routine kextmanager_lock_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_lock_kextload
(
	mach_port_t server,
	mach_port_t clientPort,
	int *lockstatus
);

/* Routine kextmanager_unlock_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_unlock_kextload
(
	mach_port_t server,
	mach_port_t clientPort
);

/* Routine kextmanager_record_path_for_bundle_id */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kextmanager_record_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path
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

#ifndef __Request__kextmanager_subsystem__defined
#define __Request__kextmanager_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
	} __Request__kextmanager_path_for_bundle_id_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		property_key_t prop_key;
	} __Request__kextmanager_create_property_value_array_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
		AuthorizationExternalForm authref;
	} __Request__kextmanager_user_did_log_in_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
	} __Request__kextmanager_user_will_log_out_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__kextmanager_get_logged_in_userid_t;
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
		mach_msg_ool_descriptor_t load_data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t load_dataCnt;
	} __Request__kextmanager_record_nonsecure_kextload_t;
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
		mach_msg_port_descriptor_t reaper;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int waitForLock;
	} __Request__kextmanager_lock_reboot_t;
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
		mach_msg_port_descriptor_t reaper;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		uuid_t vol_uuid;
		int waitForLock;
	} __Request__kextmanager_lock_volume_t;
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
		mach_msg_port_descriptor_t clientIdent;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		uuid_t vol_uuid;
		int exitStatus;
	} __Request__kextmanager_unlock_volume_t;
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
		mach_msg_port_descriptor_t clientPort;
		/* end of the kernel processed data */
	} __Request__kextmanager_lock_kextload_t;
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
		mach_msg_port_descriptor_t clientPort;
		/* end of the kernel processed data */
	} __Request__kextmanager_unlock_kextload_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
		posix_path_t path;
	} __Request__kextmanager_record_path_for_bundle_id_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__kextmanager_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__kextmanager_subsystem__defined
#define __RequestUnion__kextmanager_subsystem__defined
union __RequestUnion__kextmanager_subsystem {
	__Request__kextmanager_path_for_bundle_id_t Request_kextmanager_path_for_bundle_id;
	__Request__kextmanager_create_property_value_array_t Request_kextmanager_create_property_value_array;
	__Request__kextmanager_user_did_log_in_t Request_kextmanager_user_did_log_in;
	__Request__kextmanager_user_will_log_out_t Request_kextmanager_user_will_log_out;
	__Request__kextmanager_get_logged_in_userid_t Request_kextmanager_get_logged_in_userid;
	__Request__kextmanager_record_nonsecure_kextload_t Request_kextmanager_record_nonsecure_kextload;
	__Request__kextmanager_lock_reboot_t Request_kextmanager_lock_reboot;
	__Request__kextmanager_lock_volume_t Request_kextmanager_lock_volume;
	__Request__kextmanager_unlock_volume_t Request_kextmanager_unlock_volume;
	__Request__kextmanager_lock_kextload_t Request_kextmanager_lock_kextload;
	__Request__kextmanager_unlock_kextload_t Request_kextmanager_unlock_kextload;
	__Request__kextmanager_record_path_for_bundle_id_t Request_kextmanager_record_path_for_bundle_id;
};
#endif /* !__RequestUnion__kextmanager_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__kextmanager_subsystem__defined
#define __Reply__kextmanager_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		posix_path_t path;
		kext_result_t kext_result;
	} __Reply__kextmanager_path_for_bundle_id_t;
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
	} __Reply__kextmanager_create_property_value_array_t;
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
	} __Reply__kextmanager_user_did_log_in_t;
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
	} __Reply__kextmanager_user_will_log_out_t;
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
		uint32_t euid;
	} __Reply__kextmanager_get_logged_in_userid_t;
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
	} __Reply__kextmanager_record_nonsecure_kextload_t;
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
		mountpoint_t busyVol;
		char busyVolPad[2];
		int busyStatus;
	} __Reply__kextmanager_lock_reboot_t;
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
		int lockStatus;
	} __Reply__kextmanager_lock_volume_t;
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
	} __Reply__kextmanager_unlock_volume_t;
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
		int lockstatus;
	} __Reply__kextmanager_lock_kextload_t;
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
	} __Reply__kextmanager_unlock_kextload_t;
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
	} __Reply__kextmanager_record_path_for_bundle_id_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__kextmanager_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__kextmanager_subsystem__defined
#define __ReplyUnion__kextmanager_subsystem__defined
union __ReplyUnion__kextmanager_subsystem {
	__Reply__kextmanager_path_for_bundle_id_t Reply_kextmanager_path_for_bundle_id;
	__Reply__kextmanager_create_property_value_array_t Reply_kextmanager_create_property_value_array;
	__Reply__kextmanager_user_did_log_in_t Reply_kextmanager_user_did_log_in;
	__Reply__kextmanager_user_will_log_out_t Reply_kextmanager_user_will_log_out;
	__Reply__kextmanager_get_logged_in_userid_t Reply_kextmanager_get_logged_in_userid;
	__Reply__kextmanager_record_nonsecure_kextload_t Reply_kextmanager_record_nonsecure_kextload;
	__Reply__kextmanager_lock_reboot_t Reply_kextmanager_lock_reboot;
	__Reply__kextmanager_lock_volume_t Reply_kextmanager_lock_volume;
	__Reply__kextmanager_unlock_volume_t Reply_kextmanager_unlock_volume;
	__Reply__kextmanager_lock_kextload_t Reply_kextmanager_lock_kextload;
	__Reply__kextmanager_unlock_kextload_t Reply_kextmanager_unlock_kextload;
	__Reply__kextmanager_record_path_for_bundle_id_t Reply_kextmanager_record_path_for_bundle_id;
};
#endif /* !__RequestUnion__kextmanager_subsystem__defined */

#ifndef subsystem_to_name_map_kextmanager
#define subsystem_to_name_map_kextmanager \
    { "kextmanager_path_for_bundle_id", 70000 },\
    { "kextmanager_create_property_value_array", 70001 },\
    { "kextmanager_user_did_log_in", 70002 },\
    { "kextmanager_user_will_log_out", 70003 },\
    { "kextmanager_get_logged_in_userid", 70004 },\
    { "kextmanager_record_nonsecure_kextload", 70005 },\
    { "kextmanager_lock_reboot", 70006 },\
    { "kextmanager_lock_volume", 70007 },\
    { "kextmanager_unlock_volume", 70008 },\
    { "kextmanager_lock_kextload", 70009 },\
    { "kextmanager_unlock_kextload", 70010 },\
    { "kextmanager_record_path_for_bundle_id", 70011 }
#endif

#ifdef __AfterMigUserHeader
__AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#endif	 /* _kextmanager_user_ */
