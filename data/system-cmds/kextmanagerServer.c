/*
 * IDENTIFICATION:
 * stub generated Mon Dec 31 12:08:43 2007
 * with a MiG generated Mon Sep 11 19:11:05 PDT 2006 by root@b09.apple.com
 * OPTIONS: 
 */

/* Module kextmanager */

#define	__MIG_check__Request__kextmanager_subsystem__ 1
#define	__NDR_convert__Request__kextmanager_subsystem__ 1

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <Security/Authorization.h>
#include <IOKit/kext/kextmanager_types.h>
#include <mach/kmod.h>
#include <sys/param.h>

#ifndef	mig_internal
#define	mig_internal	static __inline__
#endif	/* mig_internal */

#ifndef	mig_external
#define mig_external
#endif	/* mig_external */

#if	!defined(__MigTypeCheck) && defined(TypeCheck)
#define	__MigTypeCheck		TypeCheck	/* Legacy setting */
#endif	/* !defined(__MigTypeCheck) */

#if	!defined(__MigKernelSpecificCode) && defined(_MIG_KERNEL_SPECIFIC_CODE_)
#define	__MigKernelSpecificCode	_MIG_KERNEL_SPECIFIC_CODE_	/* Legacy setting */
#endif	/* !defined(__MigKernelSpecificCode) */

#ifndef	LimitCheck
#define	LimitCheck 0
#endif	/* LimitCheck */

#ifndef	min
#define	min(a,b)  ( ((a) < (b))? (a): (b) )
#endif	/* min */

#if !defined(_WALIGN_)
#define _WALIGN_(x) (((x) + 3) & ~3)
#endif /* !defined(_WALIGN_) */

#if !defined(_WALIGNSZ_)
#define _WALIGNSZ_(x) _WALIGN_(sizeof(x))
#endif /* !defined(_WALIGNSZ_) */

#ifndef	UseStaticTemplates
#define	UseStaticTemplates	0
#endif	/* UseStaticTemplates */

#ifndef	__DeclareRcvRpc
#define	__DeclareRcvRpc(_NUM_, _NAME_)
#endif	/* __DeclareRcvRpc */

#ifndef	__BeforeRcvRpc
#define	__BeforeRcvRpc(_NUM_, _NAME_)
#endif	/* __BeforeRcvRpc */

#ifndef	__AfterRcvRpc
#define	__AfterRcvRpc(_NUM_, _NAME_)
#endif	/* __AfterRcvRpc */

#ifndef	__DeclareRcvSimple
#define	__DeclareRcvSimple(_NUM_, _NAME_)
#endif	/* __DeclareRcvSimple */

#ifndef	__BeforeRcvSimple
#define	__BeforeRcvSimple(_NUM_, _NAME_)
#endif	/* __BeforeRcvSimple */

#ifndef	__AfterRcvSimple
#define	__AfterRcvSimple(_NUM_, _NAME_)
#endif	/* __AfterRcvSimple */

#define novalue void

#define msgh_request_port	msgh_local_port
#define MACH_MSGH_BITS_REQUEST(bits)	MACH_MSGH_BITS_LOCAL(bits)
#define msgh_reply_port		msgh_remote_port
#define MACH_MSGH_BITS_REPLY(bits)	MACH_MSGH_BITS_REMOTE(bits)

#define MIG_RETURN_ERROR(X, code)	{\
				((mig_reply_error_t *)X)->RetCode = code;\
				((mig_reply_error_t *)X)->NDR = NDR_record;\
				return;\
				}

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

#ifndef __ReplyUnion___kextmanager_subsystem__defined
#define __ReplyUnion___kextmanager_subsystem__defined
union __ReplyUnion___kextmanager_subsystem {
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
#endif /* __RequestUnion___kextmanager_subsystem__defined */
/* Forward Declarations */


mig_internal novalue _Xkextmanager_path_for_bundle_id
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_create_property_value_array
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_user_did_log_in
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_user_will_log_out
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_get_logged_in_userid
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_record_nonsecure_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_lock_reboot
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_lock_volume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_unlock_volume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_lock_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_unlock_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);

mig_internal novalue _Xkextmanager_record_path_for_bundle_id
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP);


#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_path_for_bundle_id_t__defined)
#define __MIG_check__Request__kextmanager_path_for_bundle_id_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__int_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__int_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__char_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__char_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__char_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__float_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__float_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__float_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_path_for_bundle_id_t(__Request__kextmanager_path_for_bundle_id_t *In0P)
{

	typedef __Request__kextmanager_path_for_bundle_id_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_path_for_bundle_id_t__bundle_id__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_path_for_bundle_id_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_path_for_bundle_id */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path,
	kext_result_t *kext_result
);

/* Routine kextmanager_path_for_bundle_id */
mig_internal novalue _Xkextmanager_path_for_bundle_id
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_path_for_bundle_id_t __Request;
	typedef __Reply__kextmanager_path_for_bundle_id_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_path_for_bundle_id_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_path_for_bundle_id_t__defined */

	__DeclareRcvRpc(70000, "kextmanager_path_for_bundle_id")
	__BeforeRcvRpc(70000, "kextmanager_path_for_bundle_id")

#if	defined(__MIG_check__Request__kextmanager_path_for_bundle_id_t__defined)
	check_result = __MIG_check__Request__kextmanager_path_for_bundle_id_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_path_for_bundle_id_t__defined) */

	OutP->RetCode = _kextmanager_path_for_bundle_id(In0P->Head.msgh_request_port, In0P->bundle_id, OutP->path, &OutP->kext_result);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(70000, "kextmanager_path_for_bundle_id")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_create_property_value_array_t__defined)
#define __MIG_check__Request__kextmanager_create_property_value_array_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#if	defined(__NDR_convert__int_rep__kextmanager__property_key_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__int_rep__kextmanager__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__property_key_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__int_rep__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#if	defined(__NDR_convert__char_rep__kextmanager__property_key_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__char_rep__kextmanager__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__property_key_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__char_rep__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#if	defined(__NDR_convert__float_rep__kextmanager__property_key_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__float_rep__kextmanager__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__property_key_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__float_rep__property_key_t((property_key_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined
#define	__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 128, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_create_property_value_array_t(__Request__kextmanager_create_property_value_array_t *In0P)
{

	typedef __Request__kextmanager_create_property_value_array_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
		__NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key(&In0P->prop_key, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
		__NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key(&In0P->prop_key, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined)
		__NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key(&In0P->prop_key, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_create_property_value_array_t__prop_key__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_create_property_value_array_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_create_property_value_array */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_create_property_value_array
(
	mach_port_t server,
	property_key_t prop_key,
	xmlDataOut_t *data,
	mach_msg_type_number_t *dataCnt
);

/* Routine kextmanager_create_property_value_array */
mig_internal novalue _Xkextmanager_create_property_value_array
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		property_key_t prop_key;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_create_property_value_array_t __Request;
	typedef __Reply__kextmanager_create_property_value_array_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_create_property_value_array_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_create_property_value_array_t__defined */

#if	UseStaticTemplates
	const static mach_msg_ool_descriptor_t dataTemplate = {
		/* addr = */		(void *)0,
		/* size = */		0,
		/* deal = */		TRUE,
		/* copy = */		MACH_MSG_VIRTUAL_COPY,
		/* pad2 = */		0,
		/* type = */		MACH_MSG_OOL_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	kern_return_t RetCode;
	__DeclareRcvRpc(70001, "kextmanager_create_property_value_array")
	__BeforeRcvRpc(70001, "kextmanager_create_property_value_array")

#if	defined(__MIG_check__Request__kextmanager_create_property_value_array_t__defined)
	check_result = __MIG_check__Request__kextmanager_create_property_value_array_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_create_property_value_array_t__defined) */

#if	UseStaticTemplates
	OutP->data = dataTemplate;
#else	/* UseStaticTemplates */
	OutP->data.deallocate =  TRUE;
	OutP->data.copy = MACH_MSG_VIRTUAL_COPY;
	OutP->data.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */


	RetCode = _kextmanager_create_property_value_array(In0P->Head.msgh_request_port, In0P->prop_key, (xmlDataOut_t *)&(OutP->data.address), &OutP->dataCnt);
	if (RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, RetCode);
	}
	OutP->data.size = OutP->dataCnt;


	OutP->NDR = NDR_record;


	OutP->Head.msgh_bits |= MACH_MSGH_BITS_COMPLEX;
	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	OutP->msgh_body.msgh_descriptor_count = 1;
	__AfterRcvRpc(70001, "kextmanager_create_property_value_array")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_user_did_log_in_t__defined)
#define __MIG_check__Request__kextmanager_user_did_log_in_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#if	defined(__NDR_convert__int_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__int_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined */

#ifndef __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#if	defined(__NDR_convert__int_rep__kextmanager__AuthorizationExternalForm__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__int_rep__kextmanager__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__int_rep__AuthorizationExternalForm__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__int_rep__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__unsigned32__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__int_rep__kextmanager__unsigned32)
#elif	defined(__NDR_convert__int_rep__unsigned32__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__int_rep__unsigned32)
#elif	defined(__NDR_convert__int_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__int_rep__kextmanager__uint32_t)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__int_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#if	defined(__NDR_convert__char_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__char_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#if	defined(__NDR_convert__char_rep__kextmanager__AuthorizationExternalForm__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__char_rep__kextmanager__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__char_rep__AuthorizationExternalForm__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__char_rep__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__unsigned32__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__char_rep__kextmanager__unsigned32)
#elif	defined(__NDR_convert__char_rep__unsigned32__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__char_rep__unsigned32)
#elif	defined(__NDR_convert__char_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__char_rep__kextmanager__uint32_t)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__char_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#if	defined(__NDR_convert__float_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__float_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#if	defined(__NDR_convert__float_rep__kextmanager__AuthorizationExternalForm__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__float_rep__kextmanager__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__float_rep__AuthorizationExternalForm__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__float_rep__AuthorizationExternalForm((AuthorizationExternalForm *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__unsigned32__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__float_rep__kextmanager__unsigned32)
#elif	defined(__NDR_convert__float_rep__unsigned32__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((unsigned32 *)(a), f, 8, __NDR_convert__float_rep__unsigned32)
#elif	defined(__NDR_convert__float_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__float_rep__kextmanager__uint32_t)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(a, f) \
	__NDR_convert__ARRAY((uint32_t *)(a), f, 8, __NDR_convert__float_rep__uint32_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_user_did_log_in_t(__Request__kextmanager_user_did_log_in_t *In0P)
{

	typedef __Request__kextmanager_user_did_log_in_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined) || \
	defined(__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined)
		__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid(&In0P->euid, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__euid__defined */
#if defined(__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
		__NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref(&In0P->authref, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_user_did_log_in_t__authref__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined) || \
	defined(__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined)
		__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid(&In0P->euid, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__euid__defined */
#if defined(__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
		__NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref(&In0P->authref, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_user_did_log_in_t__authref__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined) || \
	defined(__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined)
		__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid(&In0P->euid, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__euid__defined */
#if defined(__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined)
		__NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref(&In0P->authref, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_user_did_log_in_t__authref__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_user_did_log_in_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_user_did_log_in */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_user_did_log_in
(
	mach_port_t server,
	uint32_t euid,
	AuthorizationExternalForm authref
);

/* Routine kextmanager_user_did_log_in */
mig_internal novalue _Xkextmanager_user_did_log_in
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
		AuthorizationExternalForm authref;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_user_did_log_in_t __Request;
	typedef __Reply__kextmanager_user_did_log_in_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_user_did_log_in_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_user_did_log_in_t__defined */

	__DeclareRcvRpc(70002, "kextmanager_user_did_log_in")
	__BeforeRcvRpc(70002, "kextmanager_user_did_log_in")

#if	defined(__MIG_check__Request__kextmanager_user_did_log_in_t__defined)
	check_result = __MIG_check__Request__kextmanager_user_did_log_in_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_user_did_log_in_t__defined) */

	OutP->RetCode = _kextmanager_user_did_log_in(In0P->Head.msgh_request_port, In0P->euid, In0P->authref);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70002, "kextmanager_user_did_log_in")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_user_will_log_out_t__defined)
#define __MIG_check__Request__kextmanager_user_will_log_out_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#if	defined(__NDR_convert__int_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__int_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#if	defined(__NDR_convert__char_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__char_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#if	defined(__NDR_convert__float_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__float_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_user_will_log_out_t(__Request__kextmanager_user_will_log_out_t *In0P)
{

	typedef __Request__kextmanager_user_will_log_out_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
		__NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid(&In0P->euid, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_user_will_log_out_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
		__NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid(&In0P->euid, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_user_will_log_out_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined)
		__NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid(&In0P->euid, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_user_will_log_out_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_user_will_log_out_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_user_will_log_out */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_user_will_log_out
(
	mach_port_t server,
	uint32_t euid
);

/* Routine kextmanager_user_will_log_out */
mig_internal novalue _Xkextmanager_user_will_log_out
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_user_will_log_out_t __Request;
	typedef __Reply__kextmanager_user_will_log_out_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_user_will_log_out_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_user_will_log_out_t__defined */

	__DeclareRcvRpc(70003, "kextmanager_user_will_log_out")
	__BeforeRcvRpc(70003, "kextmanager_user_will_log_out")

#if	defined(__MIG_check__Request__kextmanager_user_will_log_out_t__defined)
	check_result = __MIG_check__Request__kextmanager_user_will_log_out_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_user_will_log_out_t__defined) */

	OutP->RetCode = _kextmanager_user_will_log_out(In0P->Head.msgh_request_port, In0P->euid);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70003, "kextmanager_user_will_log_out")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_get_logged_in_userid_t__defined)
#define __MIG_check__Request__kextmanager_get_logged_in_userid_t__defined

mig_internal kern_return_t __MIG_check__Request__kextmanager_get_logged_in_userid_t(__Request__kextmanager_get_logged_in_userid_t *In0P)
{

	typedef __Request__kextmanager_get_logged_in_userid_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_get_logged_in_userid_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_get_logged_in_userid */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_get_logged_in_userid
(
	mach_port_t server,
	uint32_t *euid
);

/* Routine kextmanager_get_logged_in_userid */
mig_internal novalue _Xkextmanager_get_logged_in_userid
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_get_logged_in_userid_t __Request;
	typedef __Reply__kextmanager_get_logged_in_userid_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_get_logged_in_userid_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_get_logged_in_userid_t__defined */

	__DeclareRcvRpc(70004, "kextmanager_get_logged_in_userid")
	__BeforeRcvRpc(70004, "kextmanager_get_logged_in_userid")

#if	defined(__MIG_check__Request__kextmanager_get_logged_in_userid_t__defined)
	check_result = __MIG_check__Request__kextmanager_get_logged_in_userid_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_get_logged_in_userid_t__defined) */

	OutP->RetCode = _kextmanager_get_logged_in_userid(In0P->Head.msgh_request_port, &OutP->euid);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(70004, "kextmanager_get_logged_in_userid")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined)
#define __MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#if	defined(__NDR_convert__int_rep__kextmanager__xmlDataIn_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__int_rep__kextmanager__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__xmlDataIn_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__int_rep__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */

#ifndef __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined
#if	defined(__NDR_convert__int_rep__kextmanager__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt(a, f) \
	__NDR_convert__int_rep__kextmanager__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#if	defined(__NDR_convert__char_rep__kextmanager__xmlDataIn_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__char_rep__kextmanager__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__xmlDataIn_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__char_rep__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#if	defined(__NDR_convert__float_rep__kextmanager__xmlDataIn_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__float_rep__kextmanager__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__xmlDataIn_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data(a, f, c) \
	__NDR_convert__float_rep__xmlDataIn_t((xmlDataIn_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_record_nonsecure_kextload_t(__Request__kextmanager_record_nonsecure_kextload_t *In0P)
{

	typedef __Request__kextmanager_record_nonsecure_kextload_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->load_data.type != MACH_MSG_OOL_DESCRIPTOR)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined) || \
	defined(__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined)
		__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt(&In0P->load_dataCnt, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_dataCnt__defined */
#if defined(__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined)
		__NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data((xmlDataIn_t)(In0P->load_data.address), In0P->NDR.int_rep, In0P->load_dataCnt);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined) || \
	0
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined)
		__NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data((xmlDataIn_t)(In0P->load_data.address), In0P->NDR.char_rep, In0P->load_dataCnt);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined) || \
	0
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined)
		__NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data((xmlDataIn_t)(In0P->load_data.address), In0P->NDR.float_rep, In0P->load_dataCnt);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_record_nonsecure_kextload_t__load_data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_record_nonsecure_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_record_nonsecure_kextload
(
	mach_port_t server,
	xmlDataIn_t load_data,
	mach_msg_type_number_t load_dataCnt
);

/* Routine kextmanager_record_nonsecure_kextload */
mig_internal novalue _Xkextmanager_record_nonsecure_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

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
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_record_nonsecure_kextload_t __Request;
	typedef __Reply__kextmanager_record_nonsecure_kextload_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined */

	__DeclareRcvRpc(70005, "kextmanager_record_nonsecure_kextload")
	__BeforeRcvRpc(70005, "kextmanager_record_nonsecure_kextload")

#if	defined(__MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined)
	check_result = __MIG_check__Request__kextmanager_record_nonsecure_kextload_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_record_nonsecure_kextload_t__defined) */

	OutP->RetCode = _kextmanager_record_nonsecure_kextload(In0P->Head.msgh_request_port, (xmlDataIn_t)(In0P->load_data.address), In0P->load_dataCnt);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70005, "kextmanager_record_nonsecure_kextload")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_lock_reboot_t__defined)
#define __MIG_check__Request__kextmanager_lock_reboot_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_lock_reboot_t(__Request__kextmanager_lock_reboot_t *In0P)
{

	typedef __Request__kextmanager_lock_reboot_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->reaper.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->reaper.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
		__NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock(&In0P->waitForLock, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
		__NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock(&In0P->waitForLock, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined)
		__NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock(&In0P->waitForLock, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_lock_reboot_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_lock_reboot_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_reboot */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_lock_reboot
(
	mach_port_t server,
	mach_port_t reply,
	mach_port_t reaper,
	int waitForLock,
	mountpoint_t busyVol,
	int *busyStatus
);

/* Routine kextmanager_lock_reboot */
mig_internal novalue _Xkextmanager_lock_reboot
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

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
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_lock_reboot_t __Request;
	typedef __Reply__kextmanager_lock_reboot_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_lock_reboot_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_lock_reboot_t__defined */

	__DeclareRcvRpc(70006, "kextmanager_lock_reboot")
	__BeforeRcvRpc(70006, "kextmanager_lock_reboot")

#if	defined(__MIG_check__Request__kextmanager_lock_reboot_t__defined)
	check_result = __MIG_check__Request__kextmanager_lock_reboot_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_lock_reboot_t__defined) */

	OutP->RetCode = _kextmanager_lock_reboot(In0P->Head.msgh_request_port, In0P->Head.msgh_reply_port, In0P->reaper.name, In0P->waitForLock, OutP->busyVol, &OutP->busyStatus);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(70006, "kextmanager_lock_reboot")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_lock_volume_t__defined)
#define __MIG_check__Request__kextmanager_lock_volume_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__int_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__int_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uuid_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__int_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__int_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__int_rep__uint8_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__int_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__char_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__char_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uuid_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__char_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__char_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__char_rep__uint8_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__char_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__float_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__float_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uuid_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__float_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__float_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__float_rep__uint8_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__float_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined
#define	__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_lock_volume_t(__Request__kextmanager_lock_volume_t *In0P)
{

	typedef __Request__kextmanager_lock_volume_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->reaper.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->reaper.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined)
		__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
		__NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock(&In0P->waitForLock, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined)
		__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
		__NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock(&In0P->waitForLock, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined)
		__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined)
		__NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock(&In0P->waitForLock, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_lock_volume_t__waitForLock__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_lock_volume_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_volume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_lock_volume
(
	mach_port_t server,
	mach_port_t reply,
	mach_port_t reaper,
	uuid_t vol_uuid,
	int waitForLock,
	int *lockStatus
);

/* Routine kextmanager_lock_volume */
mig_internal novalue _Xkextmanager_lock_volume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

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
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_lock_volume_t __Request;
	typedef __Reply__kextmanager_lock_volume_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_lock_volume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_lock_volume_t__defined */

	__DeclareRcvRpc(70007, "kextmanager_lock_volume")
	__BeforeRcvRpc(70007, "kextmanager_lock_volume")

#if	defined(__MIG_check__Request__kextmanager_lock_volume_t__defined)
	check_result = __MIG_check__Request__kextmanager_lock_volume_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_lock_volume_t__defined) */

	OutP->RetCode = _kextmanager_lock_volume(In0P->Head.msgh_request_port, In0P->Head.msgh_reply_port, In0P->reaper.name, In0P->vol_uuid, In0P->waitForLock, &OutP->lockStatus);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(70007, "kextmanager_lock_volume")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_unlock_volume_t__defined)
#define __MIG_check__Request__kextmanager_unlock_volume_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__int_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__int_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uuid_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__int_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__int_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__int_rep__uint8_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__int_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__char_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__char_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uuid_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__char_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__char_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__char_rep__uint8_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__char_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#if	defined(__NDR_convert__float_rep__kextmanager__uuid_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__float_rep__kextmanager__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uuid_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__float_rep__uuid_t((uuid_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__uint8_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__float_rep__kextmanager__uint8_t)
#elif	defined(__NDR_convert__float_rep__uint8_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid(a, f) \
	__NDR_convert__ARRAY((uint8_t *)(a), f, 16, __NDR_convert__float_rep__uint8_t)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined
#define	__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_unlock_volume_t(__Request__kextmanager_unlock_volume_t *In0P)
{

	typedef __Request__kextmanager_unlock_volume_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->clientIdent.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->clientIdent.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined)
		__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
		__NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus(&In0P->exitStatus, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined)
		__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
		__NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus(&In0P->exitStatus, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined) || \
	defined(__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined)
		__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid(&In0P->vol_uuid, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__vol_uuid__defined */
#if defined(__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined)
		__NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus(&In0P->exitStatus, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_unlock_volume_t__exitStatus__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_unlock_volume_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_unlock_volume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_unlock_volume
(
	mach_port_t server,
	mach_port_t clientIdent,
	uuid_t vol_uuid,
	int exitStatus
);

/* Routine kextmanager_unlock_volume */
mig_internal novalue _Xkextmanager_unlock_volume
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

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
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_unlock_volume_t __Request;
	typedef __Reply__kextmanager_unlock_volume_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_unlock_volume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_unlock_volume_t__defined */

	__DeclareRcvRpc(70008, "kextmanager_unlock_volume")
	__BeforeRcvRpc(70008, "kextmanager_unlock_volume")

#if	defined(__MIG_check__Request__kextmanager_unlock_volume_t__defined)
	check_result = __MIG_check__Request__kextmanager_unlock_volume_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_unlock_volume_t__defined) */

	OutP->RetCode = _kextmanager_unlock_volume(In0P->Head.msgh_request_port, In0P->clientIdent.name, In0P->vol_uuid, In0P->exitStatus);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70008, "kextmanager_unlock_volume")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_lock_kextload_t__defined)
#define __MIG_check__Request__kextmanager_lock_kextload_t__defined

mig_internal kern_return_t __MIG_check__Request__kextmanager_lock_kextload_t(__Request__kextmanager_lock_kextload_t *In0P)
{

	typedef __Request__kextmanager_lock_kextload_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->clientPort.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->clientPort.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_lock_kextload_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_lock_kextload
(
	mach_port_t server,
	mach_port_t clientPort,
	int *lockstatus
);

/* Routine kextmanager_lock_kextload */
mig_internal novalue _Xkextmanager_lock_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t clientPort;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_lock_kextload_t __Request;
	typedef __Reply__kextmanager_lock_kextload_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_lock_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_lock_kextload_t__defined */

	__DeclareRcvRpc(70009, "kextmanager_lock_kextload")
	__BeforeRcvRpc(70009, "kextmanager_lock_kextload")

#if	defined(__MIG_check__Request__kextmanager_lock_kextload_t__defined)
	check_result = __MIG_check__Request__kextmanager_lock_kextload_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_lock_kextload_t__defined) */

	OutP->RetCode = _kextmanager_lock_kextload(In0P->Head.msgh_request_port, In0P->clientPort.name, &OutP->lockstatus);
	if (OutP->RetCode != KERN_SUCCESS) {
		MIG_RETURN_ERROR(OutP, OutP->RetCode);
	}

	OutP->NDR = NDR_record;


	OutP->Head.msgh_size = (mach_msg_size_t)(sizeof(Reply));
	__AfterRcvRpc(70009, "kextmanager_lock_kextload")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_unlock_kextload_t__defined)
#define __MIG_check__Request__kextmanager_unlock_kextload_t__defined

mig_internal kern_return_t __MIG_check__Request__kextmanager_unlock_kextload_t(__Request__kextmanager_unlock_kextload_t *In0P)
{

	typedef __Request__kextmanager_unlock_kextload_t __Request;
#if	__MigTypeCheck
	if (!(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->msgh_body.msgh_descriptor_count != 1) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (In0P->clientPort.type != MACH_MSG_PORT_DESCRIPTOR ||
	    In0P->clientPort.disposition != 17)
		return MIG_TYPE_ERROR;
#endif	/* __MigTypeCheck */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_unlock_kextload_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_unlock_kextload */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_unlock_kextload
(
	mach_port_t server,
	mach_port_t clientPort
);

/* Routine kextmanager_unlock_kextload */
mig_internal novalue _Xkextmanager_unlock_kextload
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t clientPort;
		/* end of the kernel processed data */
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_unlock_kextload_t __Request;
	typedef __Reply__kextmanager_unlock_kextload_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_unlock_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_unlock_kextload_t__defined */

	__DeclareRcvRpc(70010, "kextmanager_unlock_kextload")
	__BeforeRcvRpc(70010, "kextmanager_unlock_kextload")

#if	defined(__MIG_check__Request__kextmanager_unlock_kextload_t__defined)
	check_result = __MIG_check__Request__kextmanager_unlock_kextload_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_unlock_kextload_t__defined) */

	OutP->RetCode = _kextmanager_unlock_kextload(In0P->Head.msgh_request_port, In0P->clientPort.name);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70010, "kextmanager_unlock_kextload")
}

#if (__MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Request__kextmanager_subsystem__
#if !defined(__MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined)
#define __MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined
#ifndef __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__int_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__int_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */

#ifndef __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__int_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__int_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__posix_path_t__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__int_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__char_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__char_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__char_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */

#ifndef __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__char_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__char_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__posix_path_t__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__char_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#if	defined(__NDR_convert__float_rep__kextmanager__kext_bundle_id_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__float_rep__kextmanager__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kext_bundle_id_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__float_rep__kext_bundle_id_t((kext_bundle_id_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 64, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */

#ifndef __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__float_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__float_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__posix_path_t__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__float_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */


mig_internal kern_return_t __MIG_check__Request__kextmanager_record_path_for_bundle_id_t(__Request__kextmanager_record_path_for_bundle_id_t *In0P)
{

	typedef __Request__kextmanager_record_path_for_bundle_id_t __Request;
#if	__MigTypeCheck
	if ((In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (In0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Request)))
		return MIG_BAD_ARGUMENTS;
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined) || \
	defined(__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
	if (In0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */
#if defined(__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
		__NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path(&In0P->path, In0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined) || \
	defined(__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
	if (In0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */
#if defined(__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
		__NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path(&In0P->path, In0P->NDR.char_rep);
#endif	/* __NDR_convert__char_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined) || \
	defined(__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
	if (In0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined)
		__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id(&In0P->bundle_id, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__bundle_id__defined */
#if defined(__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined)
		__NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path(&In0P->path, In0P->NDR.float_rep);
#endif	/* __NDR_convert__float_rep__Request__kextmanager_record_path_for_bundle_id_t__path__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined) */
#endif /* __MIG_check__Request__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_record_path_for_bundle_id */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _kextmanager_record_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path
);

/* Routine kextmanager_record_path_for_bundle_id */
mig_internal novalue _Xkextmanager_record_path_for_bundle_id
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
		posix_path_t path;
		mach_msg_trailer_t trailer;
	} Request;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	typedef __Request__kextmanager_record_path_for_bundle_id_t __Request;
	typedef __Reply__kextmanager_record_path_for_bundle_id_t Reply;

	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	Request *In0P = (Request *) InHeadP;
	Reply *OutP = (Reply *) OutHeadP;
#ifdef	__MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined */

	__DeclareRcvRpc(70011, "kextmanager_record_path_for_bundle_id")
	__BeforeRcvRpc(70011, "kextmanager_record_path_for_bundle_id")

#if	defined(__MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined)
	check_result = __MIG_check__Request__kextmanager_record_path_for_bundle_id_t((__Request *)In0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ MIG_RETURN_ERROR(OutP, check_result); }
#endif	/* defined(__MIG_check__Request__kextmanager_record_path_for_bundle_id_t__defined) */

	OutP->RetCode = _kextmanager_record_path_for_bundle_id(In0P->Head.msgh_request_port, In0P->bundle_id, In0P->path);

	OutP->NDR = NDR_record;


	__AfterRcvRpc(70011, "kextmanager_record_path_for_bundle_id")
}


extern boolean_t kextmanager_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t kextmanager_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
const struct _kextmanager_subsystem {
	mig_server_routine_t 	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[12];
} _kextmanager_subsystem = {
	kextmanager_server_routine,
	70000,
	70012,
	(mach_msg_size_t)sizeof(union __ReplyUnion___kextmanager_subsystem),
	(vm_address_t)0,
	{
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_path_for_bundle_id, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_path_for_bundle_id_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_create_property_value_array, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_create_property_value_array_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_user_did_log_in, 10, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_user_did_log_in_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_user_will_log_out, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_user_will_log_out_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_get_logged_in_userid, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_get_logged_in_userid_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_record_nonsecure_kextload, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_record_nonsecure_kextload_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_lock_reboot, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_lock_reboot_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_lock_volume, 6, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_lock_volume_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_unlock_volume, 4, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_unlock_volume_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_lock_kextload, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_lock_kextload_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_unlock_kextload, 2, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_unlock_kextload_t)},
          { (mig_impl_routine_t) 0,
            (mig_stub_routine_t) _Xkextmanager_record_path_for_bundle_id, 3, 0, (routine_arg_descriptor_t)0, (mach_msg_size_t)sizeof(__Reply__kextmanager_record_path_for_bundle_id_t)},
	}
};

mig_external boolean_t kextmanager_server
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	register mig_routine_t routine;

	OutHeadP->msgh_bits = MACH_MSGH_BITS(MACH_MSGH_BITS_REPLY(InHeadP->msgh_bits), 0);
	OutHeadP->msgh_remote_port = InHeadP->msgh_reply_port;
	/* Minimal size: routine() will update it if different */
	OutHeadP->msgh_size = (mach_msg_size_t)sizeof(mig_reply_error_t);
	OutHeadP->msgh_local_port = MACH_PORT_NULL;
	OutHeadP->msgh_id = InHeadP->msgh_id + 100;

	if ((InHeadP->msgh_id > 70011) || (InHeadP->msgh_id < 70000) ||
	    ((routine = _kextmanager_subsystem.routine[InHeadP->msgh_id - 70000].stub_routine) == 0)) {
		((mig_reply_error_t *)OutHeadP)->NDR = NDR_record;
		((mig_reply_error_t *)OutHeadP)->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InHeadP, OutHeadP);
	return TRUE;
}

mig_external mig_routine_t kextmanager_server_routine
	(mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 70000;

	if ((msgh_id > 11) || (msgh_id < 0))
		return 0;

	return _kextmanager_subsystem.routine[msgh_id].stub_routine;
}
