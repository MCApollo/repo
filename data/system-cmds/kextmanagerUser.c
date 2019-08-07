/*
 * IDENTIFICATION:
 * stub generated Mon Dec 31 12:08:43 2007
 * with a MiG generated Mon Sep 11 19:11:05 PDT 2006 by root@b09.apple.com
 * OPTIONS: 
 */
#define	__MIG_check__Reply__kextmanager_subsystem__ 1
#define	__NDR_convert__Reply__kextmanager_subsystem__ 1
#define	__NDR_convert__mig_reply_error_subsystem__ 1

#include "kextmanager.h"


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

#ifndef	__MachMsgErrorWithTimeout
#define	__MachMsgErrorWithTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_REPLY: \
	case MACH_RCV_INVALID_NAME: \
	case MACH_RCV_PORT_DIED: \
	case MACH_RCV_PORT_CHANGED: \
	case MACH_RCV_TIMED_OUT: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithTimeout */

#ifndef	__MachMsgErrorWithoutTimeout
#define	__MachMsgErrorWithoutTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_REPLY: \
	case MACH_RCV_INVALID_NAME: \
	case MACH_RCV_PORT_DIED: \
	case MACH_RCV_PORT_CHANGED: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithoutTimeout */

#ifndef	__DeclareSendRpc
#define	__DeclareSendRpc(_NUM_, _NAME_)
#endif	/* __DeclareSendRpc */

#ifndef	__BeforeSendRpc
#define	__BeforeSendRpc(_NUM_, _NAME_)
#endif	/* __BeforeSendRpc */

#ifndef	__AfterSendRpc
#define	__AfterSendRpc(_NUM_, _NAME_)
#endif	/* __AfterSendRpc */

#ifndef	__DeclareSendSimple
#define	__DeclareSendSimple(_NUM_, _NAME_)
#endif	/* __DeclareSendSimple */

#ifndef	__BeforeSendSimple
#define	__BeforeSendSimple(_NUM_, _NAME_)
#endif	/* __BeforeSendSimple */

#ifndef	__AfterSendSimple
#define	__AfterSendSimple(_NUM_, _NAME_)
#endif	/* __AfterSendSimple */

#define msgh_request_port	msgh_remote_port
#define msgh_reply_port		msgh_local_port



#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined)
#define __MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__int_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__int_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__posix_path_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__int_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kext_result_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__kextmanager__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kext_result_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */



#ifndef __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__char_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__char_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__posix_path_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__char_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */


#ifndef __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#if	defined(__NDR_convert__char_rep__kextmanager__kext_result_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__kextmanager__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kext_result_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#if	defined(__NDR_convert__float_rep__kextmanager__posix_path_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__float_rep__kextmanager__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__posix_path_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__float_rep__posix_path_t((posix_path_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 1024, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */


#ifndef __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#if	defined(__NDR_convert__float_rep__kextmanager__kext_result_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__kextmanager__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kext_result_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__kext_result_t((kext_result_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */



mig_internal kern_return_t __MIG_check__Reply__kextmanager_path_for_bundle_id_t(__Reply__kextmanager_path_for_bundle_id_t *Out0P)
{

	typedef __Reply__kextmanager_path_for_bundle_id_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70100) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined)
		__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path(&Out0P->path, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
		__NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(&Out0P->kext_result, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined) || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined)
		__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path(&Out0P->path, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */
#if defined(__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
		__NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(&Out0P->kext_result, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined) || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined)
		__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path(&Out0P->path, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__path__defined */
#if defined(__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined)
		__NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result(&Out0P->kext_result, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_path_for_bundle_id_t__kext_result__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_path_for_bundle_id */
mig_external kern_return_t kextmanager_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path,
	kext_result_t *kext_result
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
	} Request;
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
		posix_path_t path;
		kext_result_t kext_result;
		mach_msg_trailer_t trailer;
	} Reply;
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
		posix_path_t path;
		kext_result_t kext_result;
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined */

	__DeclareSendRpc(70000, "kextmanager_path_for_bundle_id")

	InP->NDR = NDR_record;

	{   typedef struct { char data[64]; } *sp;
	    * (sp) InP->bundle_id = * (sp) bundle_id;
	}

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70000;

	__BeforeSendRpc(70000, "kextmanager_path_for_bundle_id")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70000, "kextmanager_path_for_bundle_id")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined)
	check_result = __MIG_check__Reply__kextmanager_path_for_bundle_id_t((__Reply__kextmanager_path_for_bundle_id_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_path_for_bundle_id_t__defined) */

	{   typedef struct { char data[1024]; } *sp;
	    * (sp) path = * (sp) Out0P->path;
	}

	*kext_result = Out0P->kext_result;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_create_property_value_array_t__defined)
#define __MIG_check__Reply__kextmanager_create_property_value_array_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#if	defined(__NDR_convert__int_rep__kextmanager__xmlDataOut_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__int_rep__kextmanager__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__xmlDataOut_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__int_rep__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined
#if	defined(__NDR_convert__int_rep__kextmanager__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt(a, f) \
	__NDR_convert__int_rep__kextmanager__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined */


#ifndef __NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#if	defined(__NDR_convert__char_rep__kextmanager__xmlDataOut_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__char_rep__kextmanager__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__xmlDataOut_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__char_rep__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#if	defined(__NDR_convert__float_rep__kextmanager__xmlDataOut_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__float_rep__kextmanager__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__xmlDataOut_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data(a, f, c) \
	__NDR_convert__float_rep__xmlDataOut_t((xmlDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined */




mig_internal kern_return_t __MIG_check__Reply__kextmanager_create_property_value_array_t(__Reply__kextmanager_create_property_value_array_t *Out0P)
{

	typedef __Reply__kextmanager_create_property_value_array_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70101) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

	msgh_simple = !(Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX);
#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((msgh_simple || Out0P->msgh_body.msgh_descriptor_count != 1 ||
	    msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	    (!msgh_simple || msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	    ((mig_reply_error_t *)Out0P)->RetCode == KERN_SUCCESS))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (msgh_simple) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	__MigTypeCheck
	if (Out0P->data.type != MACH_MSG_OOL_DESCRIPTOR)
		{ return MIG_TYPE_ERROR; }
#endif	/* __MigTypeCheck */

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined)
		__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt(&Out0P->dataCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__dataCnt__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined)
		__NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data((xmlDataOut_t)(Out0P->data.address), Out0P->NDR.int_rep, Out0P->dataCnt);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_create_property_value_array_t__data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined)
		__NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data((xmlDataOut_t)(Out0P->data.address), Out0P->NDR.char_rep, Out0P->dataCnt);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_create_property_value_array_t__data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined)
		__NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data((xmlDataOut_t)(Out0P->data.address), Out0P->NDR.float_rep, Out0P->dataCnt);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_create_property_value_array_t__data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_create_property_value_array_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_create_property_value_array */
mig_external kern_return_t kextmanager_create_property_value_array
(
	mach_port_t server,
	property_key_t prop_key,
	xmlDataOut_t *data,
	mach_msg_type_number_t *dataCnt
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		property_key_t prop_key;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_create_property_value_array_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_create_property_value_array_t__defined */

	__DeclareSendRpc(70001, "kextmanager_create_property_value_array")

	InP->NDR = NDR_record;

	{   typedef struct { char data[128]; } *sp;
	    * (sp) InP->prop_key = * (sp) prop_key;
	}

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70001;

	__BeforeSendRpc(70001, "kextmanager_create_property_value_array")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70001, "kextmanager_create_property_value_array")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_create_property_value_array_t__defined)
	check_result = __MIG_check__Reply__kextmanager_create_property_value_array_t((__Reply__kextmanager_create_property_value_array_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_create_property_value_array_t__defined) */

	*data = (xmlDataOut_t)(Out0P->data.address);
	*dataCnt = Out0P->dataCnt;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_user_did_log_in_t__defined)
#define __MIG_check__Reply__kextmanager_user_did_log_in_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_user_did_log_in_t(__Reply__kextmanager_user_did_log_in_t *Out0P)
{

	typedef __Reply__kextmanager_user_did_log_in_t __Reply;
	if (Out0P->Head.msgh_id != 70102) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_user_did_log_in_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_user_did_log_in_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_user_did_log_in */
mig_external kern_return_t kextmanager_user_did_log_in
(
	mach_port_t server,
	uint32_t euid,
	AuthorizationExternalForm authref
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
		AuthorizationExternalForm authref;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_user_did_log_in_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_user_did_log_in_t__defined */

	__DeclareSendRpc(70002, "kextmanager_user_did_log_in")

	InP->NDR = NDR_record;

	InP->euid = euid;

	InP->authref = authref;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70002;

	__BeforeSendRpc(70002, "kextmanager_user_did_log_in")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70002, "kextmanager_user_did_log_in")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_user_did_log_in_t__defined)
	check_result = __MIG_check__Reply__kextmanager_user_did_log_in_t((__Reply__kextmanager_user_did_log_in_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_user_did_log_in_t__defined) */

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_user_will_log_out_t__defined)
#define __MIG_check__Reply__kextmanager_user_will_log_out_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_user_will_log_out_t(__Reply__kextmanager_user_will_log_out_t *Out0P)
{

	typedef __Reply__kextmanager_user_will_log_out_t __Reply;
	if (Out0P->Head.msgh_id != 70103) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_user_will_log_out_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_user_will_log_out_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_user_will_log_out */
mig_external kern_return_t kextmanager_user_will_log_out
(
	mach_port_t server,
	uint32_t euid
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint32_t euid;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_user_will_log_out_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_user_will_log_out_t__defined */

	__DeclareSendRpc(70003, "kextmanager_user_will_log_out")

	InP->NDR = NDR_record;

	InP->euid = euid;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70003;

	__BeforeSendRpc(70003, "kextmanager_user_will_log_out")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70003, "kextmanager_user_will_log_out")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_user_will_log_out_t__defined)
	check_result = __MIG_check__Reply__kextmanager_user_will_log_out_t((__Reply__kextmanager_user_will_log_out_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_user_will_log_out_t__defined) */

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined)
#define __MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#if	defined(__NDR_convert__int_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__int_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__uint32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__int_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */



#ifndef __NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#if	defined(__NDR_convert__char_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__char_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__uint32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__char_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#if	defined(__NDR_convert__float_rep__kextmanager__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__float_rep__kextmanager__uint32_t((uint32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__uint32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid(a, f) \
	__NDR_convert__float_rep__uint32_t((uint32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */



mig_internal kern_return_t __MIG_check__Reply__kextmanager_get_logged_in_userid_t(__Reply__kextmanager_get_logged_in_userid_t *Out0P)
{

	typedef __Reply__kextmanager_get_logged_in_userid_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70104) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
		__NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid(&Out0P->euid, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
		__NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid(&Out0P->euid, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined)
		__NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid(&Out0P->euid, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_get_logged_in_userid_t__euid__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_get_logged_in_userid */
mig_external kern_return_t kextmanager_get_logged_in_userid
(
	mach_port_t server,
	uint32_t *euid
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined */

	__DeclareSendRpc(70004, "kextmanager_get_logged_in_userid")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70004;

	__BeforeSendRpc(70004, "kextmanager_get_logged_in_userid")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70004, "kextmanager_get_logged_in_userid")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined)
	check_result = __MIG_check__Reply__kextmanager_get_logged_in_userid_t((__Reply__kextmanager_get_logged_in_userid_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_get_logged_in_userid_t__defined) */

	*euid = Out0P->euid;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined)
#define __MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_record_nonsecure_kextload_t(__Reply__kextmanager_record_nonsecure_kextload_t *Out0P)
{

	typedef __Reply__kextmanager_record_nonsecure_kextload_t __Reply;
	if (Out0P->Head.msgh_id != 70105) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_record_nonsecure_kextload_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_record_nonsecure_kextload */
mig_external kern_return_t kextmanager_record_nonsecure_kextload
(
	mach_port_t server,
	xmlDataIn_t load_data,
	mach_msg_type_number_t load_dataCnt
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined */

	__DeclareSendRpc(70005, "kextmanager_record_nonsecure_kextload")

#if	UseStaticTemplates
	const static mach_msg_ool_descriptor_t load_dataTemplate = {
		/* addr = */		(void *)0,
		/* size = */		0,
		/* deal = */		FALSE,
		/* copy = */		MACH_MSG_VIRTUAL_COPY,
		/* pad2 = */		0,
		/* type = */		MACH_MSG_OOL_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->load_data = load_dataTemplate;
	InP->load_data.address = (void *)(load_data);
	InP->load_data.size = load_dataCnt;
#else	/* UseStaticTemplates */
	InP->load_data.address = (void *)(load_data);
	InP->load_data.size = load_dataCnt;
	InP->load_data.deallocate =  FALSE;
	InP->load_data.copy = MACH_MSG_VIRTUAL_COPY;
	InP->load_data.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->load_dataCnt = load_dataCnt;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70005;

	__BeforeSendRpc(70005, "kextmanager_record_nonsecure_kextload")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70005, "kextmanager_record_nonsecure_kextload")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined)
	check_result = __MIG_check__Reply__kextmanager_record_nonsecure_kextload_t((__Reply__kextmanager_record_nonsecure_kextload_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_record_nonsecure_kextload_t__defined) */

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_lock_reboot_t__defined)
#define __MIG_check__Reply__kextmanager_lock_reboot_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#if	defined(__NDR_convert__int_rep__kextmanager__mountpoint_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__int_rep__kextmanager__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mountpoint_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__int_rep__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__char__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__int_rep__kextmanager__char)
#elif	defined(__NDR_convert__int_rep__char__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__int_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */



#ifndef __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#if	defined(__NDR_convert__char_rep__kextmanager__mountpoint_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__char_rep__kextmanager__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__mountpoint_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__char_rep__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__char__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__char_rep__kextmanager__char)
#elif	defined(__NDR_convert__char_rep__char__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__char_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */


#ifndef __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#if	defined(__NDR_convert__float_rep__kextmanager__mountpoint_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__float_rep__kextmanager__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__mountpoint_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__float_rep__mountpoint_t((mountpoint_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__char__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__float_rep__kextmanager__char)
#elif	defined(__NDR_convert__float_rep__char__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol(a, f) \
	__NDR_convert__ARRAY((char *)(a), f, 90, __NDR_convert__float_rep__char)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */


#ifndef __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */



mig_internal kern_return_t __MIG_check__Reply__kextmanager_lock_reboot_t(__Reply__kextmanager_lock_reboot_t *Out0P)
{

	typedef __Reply__kextmanager_lock_reboot_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70106) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol(&Out0P->busyVol, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus(&Out0P->busyStatus, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined) || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined)
		__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol(&Out0P->busyVol, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */
#if defined(__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
		__NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus(&Out0P->busyStatus, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined) || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined)
		__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol(&Out0P->busyVol, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyVol__defined */
#if defined(__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined)
		__NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus(&Out0P->busyStatus, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_reboot_t__busyStatus__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_lock_reboot_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_reboot */
mig_external kern_return_t kextmanager_lock_reboot
(
	mach_port_t server,
	mach_port_t reaper,
	int waitForLock,
	mountpoint_t busyVol,
	int *busyStatus
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_lock_reboot_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_lock_reboot_t__defined */

	__DeclareSendRpc(70006, "kextmanager_lock_reboot")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t reaperTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->reaper = reaperTemplate;
	InP->reaper.name = reaper;
#else	/* UseStaticTemplates */
	InP->reaper.name = reaper;
	InP->reaper.disposition = 20;
	InP->reaper.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->waitForLock = waitForLock;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, 21);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70006;

	__BeforeSendRpc(70006, "kextmanager_lock_reboot")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70006, "kextmanager_lock_reboot")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_lock_reboot_t__defined)
	check_result = __MIG_check__Reply__kextmanager_lock_reboot_t((__Reply__kextmanager_lock_reboot_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_lock_reboot_t__defined) */

	{   typedef struct { char data[90]; } *sp;
	    * (sp) busyVol = * (sp) Out0P->busyVol;
	}

	*busyStatus = Out0P->busyStatus;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_lock_volume_t__defined)
#define __MIG_check__Reply__kextmanager_lock_volume_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */



#ifndef __NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */



mig_internal kern_return_t __MIG_check__Reply__kextmanager_lock_volume_t(__Reply__kextmanager_lock_volume_t *Out0P)
{

	typedef __Reply__kextmanager_lock_volume_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70107) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus(&Out0P->lockStatus, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
		__NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus(&Out0P->lockStatus, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined)
		__NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus(&Out0P->lockStatus, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_volume_t__lockStatus__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_lock_volume_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_volume */
mig_external kern_return_t kextmanager_lock_volume
(
	mach_port_t server,
	mach_port_t reaper,
	uuid_t vol_uuid,
	int waitForLock,
	int *lockStatus
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_lock_volume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_lock_volume_t__defined */

	__DeclareSendRpc(70007, "kextmanager_lock_volume")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t reaperTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->reaper = reaperTemplate;
	InP->reaper.name = reaper;
#else	/* UseStaticTemplates */
	InP->reaper.name = reaper;
	InP->reaper.disposition = 20;
	InP->reaper.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	{   typedef struct { char data[16]; } *sp;
	    * (sp) InP->vol_uuid = * (sp) vol_uuid;
	}

	InP->waitForLock = waitForLock;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, 21);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70007;

	__BeforeSendRpc(70007, "kextmanager_lock_volume")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70007, "kextmanager_lock_volume")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_lock_volume_t__defined)
	check_result = __MIG_check__Reply__kextmanager_lock_volume_t((__Reply__kextmanager_lock_volume_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_lock_volume_t__defined) */

	*lockStatus = Out0P->lockStatus;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_unlock_volume_t__defined)
#define __MIG_check__Reply__kextmanager_unlock_volume_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_unlock_volume_t(__Reply__kextmanager_unlock_volume_t *Out0P)
{

	typedef __Reply__kextmanager_unlock_volume_t __Reply;
	if (Out0P->Head.msgh_id != 70108) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_unlock_volume_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_unlock_volume_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_unlock_volume */
mig_external kern_return_t kextmanager_unlock_volume
(
	mach_port_t server,
	mach_port_t clientIdent,
	uuid_t vol_uuid,
	int exitStatus
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_unlock_volume_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_unlock_volume_t__defined */

	__DeclareSendRpc(70008, "kextmanager_unlock_volume")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t clientIdentTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->clientIdent = clientIdentTemplate;
	InP->clientIdent.name = clientIdent;
#else	/* UseStaticTemplates */
	InP->clientIdent.name = clientIdent;
	InP->clientIdent.disposition = 20;
	InP->clientIdent.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	{   typedef struct { char data[16]; } *sp;
	    * (sp) InP->vol_uuid = * (sp) vol_uuid;
	}

	InP->exitStatus = exitStatus;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70008;

	__BeforeSendRpc(70008, "kextmanager_unlock_volume")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70008, "kextmanager_unlock_volume")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_unlock_volume_t__defined)
	check_result = __MIG_check__Reply__kextmanager_unlock_volume_t((__Reply__kextmanager_unlock_volume_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_unlock_volume_t__defined) */

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_lock_kextload_t__defined)
#define __MIG_check__Reply__kextmanager_lock_kextload_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined */


#ifndef __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#if	defined(__NDR_convert__int_rep__kextmanager__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__int__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__int_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__int_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__int_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__int32_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__int_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */



#ifndef __NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#if	defined(__NDR_convert__char_rep__kextmanager__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__int__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__char_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__char_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__char_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__char_rep__int32_t__defined)
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__char_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */



#ifndef __NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#if	defined(__NDR_convert__float_rep__kextmanager__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__int__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__float_rep__int((int *)(a), f)
#elif	defined(__NDR_convert__float_rep__kextmanager__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__float_rep__kextmanager__int32_t((int32_t *)(a), f)
#elif	defined(__NDR_convert__float_rep__int32_t__defined)
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined
#define	__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus(a, f) \
	__NDR_convert__float_rep__int32_t((int32_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */



mig_internal kern_return_t __MIG_check__Reply__kextmanager_lock_kextload_t(__Reply__kextmanager_lock_kextload_t *Out0P)
{

	typedef __Reply__kextmanager_lock_kextload_t __Reply;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 70109) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

	if (Out0P->RetCode != KERN_SUCCESS) {
#ifdef	__NDR_convert__mig_reply_error_t__defined
		__NDR_convert__mig_reply_error_t((mig_reply_error_t *)Out0P);
#endif	/* __NDR_convert__mig_reply_error_t__defined */
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

#if	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined) || \
	defined(__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__RetCode__defined */
#if defined(__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
		__NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus(&Out0P->lockstatus, Out0P->NDR.int_rep);
#endif /* __NDR_convert__int_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	0 || \
	defined(__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
		__NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus(&Out0P->lockstatus, Out0P->NDR.char_rep);
#endif /* __NDR_convert__char_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	0 || \
	defined(__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined)
		__NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus(&Out0P->lockstatus, Out0P->NDR.float_rep);
#endif /* __NDR_convert__float_rep__Reply__kextmanager_lock_kextload_t__lockstatus__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__kextmanager_lock_kextload_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_lock_kextload */
mig_external kern_return_t kextmanager_lock_kextload
(
	mach_port_t server,
	mach_port_t clientPort,
	int *lockstatus
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_lock_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_lock_kextload_t__defined */

	__DeclareSendRpc(70009, "kextmanager_lock_kextload")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t clientPortTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->clientPort = clientPortTemplate;
	InP->clientPort.name = clientPort;
#else	/* UseStaticTemplates */
	InP->clientPort.name = clientPort;
	InP->clientPort.disposition = 20;
	InP->clientPort.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70009;

	__BeforeSendRpc(70009, "kextmanager_lock_kextload")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70009, "kextmanager_lock_kextload")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_lock_kextload_t__defined)
	check_result = __MIG_check__Reply__kextmanager_lock_kextload_t((__Reply__kextmanager_lock_kextload_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_lock_kextload_t__defined) */

	*lockstatus = Out0P->lockstatus;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_unlock_kextload_t__defined)
#define __MIG_check__Reply__kextmanager_unlock_kextload_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_unlock_kextload_t(__Reply__kextmanager_unlock_kextload_t *Out0P)
{

	typedef __Reply__kextmanager_unlock_kextload_t __Reply;
	if (Out0P->Head.msgh_id != 70110) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_unlock_kextload_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_unlock_kextload_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_unlock_kextload */
mig_external kern_return_t kextmanager_unlock_kextload
(
	mach_port_t server,
	mach_port_t clientPort
)
{
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
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_unlock_kextload_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_unlock_kextload_t__defined */

	__DeclareSendRpc(70010, "kextmanager_unlock_kextload")

#if	UseStaticTemplates
	const static mach_msg_port_descriptor_t clientPortTemplate = {
		/* name = */		MACH_PORT_NULL,
		/* pad1 = */		0,
		/* pad2 = */		0,
		/* disp = */		20,
		/* type = */		MACH_MSG_PORT_DESCRIPTOR,
	};
#endif	/* UseStaticTemplates */

	InP->msgh_body.msgh_descriptor_count = 1;
#if	UseStaticTemplates
	InP->clientPort = clientPortTemplate;
	InP->clientPort.name = clientPort;
#else	/* UseStaticTemplates */
	InP->clientPort.name = clientPort;
	InP->clientPort.disposition = 20;
	InP->clientPort.type = MACH_MSG_PORT_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70010;

	__BeforeSendRpc(70010, "kextmanager_unlock_kextload")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70010, "kextmanager_unlock_kextload")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_unlock_kextload_t__defined)
	check_result = __MIG_check__Reply__kextmanager_unlock_kextload_t((__Reply__kextmanager_unlock_kextload_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_unlock_kextload_t__defined) */

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__kextmanager_subsystem__
#if !defined(__MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined)
#define __MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined
#ifndef __NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__kextmanager__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode(a, f) \
	__NDR_convert__int_rep__kextmanager__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__kextmanager_record_path_for_bundle_id_t(__Reply__kextmanager_record_path_for_bundle_id_t *Out0P)
{

	typedef __Reply__kextmanager_record_path_for_bundle_id_t __Reply;
	if (Out0P->Head.msgh_id != 70111) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if defined(__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__kextmanager_record_path_for_bundle_id_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined) */
#endif /* __MIG_check__Reply__kextmanager_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine kextmanager_record_path_for_bundle_id */
mig_external kern_return_t kextmanager_record_path_for_bundle_id
(
	mach_port_t server,
	kext_bundle_id_t bundle_id,
	posix_path_t path
)
{
    {

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kext_bundle_id_t bundle_id;
		posix_path_t path;
	} Request;
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
		mach_msg_trailer_t trailer;
	} Reply;
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
	} __Reply;
#ifdef  __MigPackStructs
#pragma pack()
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined */

	__DeclareSendRpc(70011, "kextmanager_record_path_for_bundle_id")

	InP->NDR = NDR_record;

	{   typedef struct { char data[64]; } *sp;
	    * (sp) InP->bundle_id = * (sp) bundle_id;
	}

	{   typedef struct { char data[1024]; } *sp;
	    * (sp) InP->path = * (sp) path;
	}

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 70011;

	__BeforeSendRpc(70011, "kextmanager_record_path_for_bundle_id")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(70011, "kextmanager_record_path_for_bundle_id")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined)
	check_result = __MIG_check__Reply__kextmanager_record_path_for_bundle_id_t((__Reply__kextmanager_record_path_for_bundle_id_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__kextmanager_record_path_for_bundle_id_t__defined) */

	return KERN_SUCCESS;
    }
}
