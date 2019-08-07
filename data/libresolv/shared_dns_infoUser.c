/*
 * IDENTIFICATION:
 * stub generated Tue Jan  1 16:42:09 2008
 * with a MiG generated Mon Sep 11 19:11:05 PDT 2006 by root@b09.apple.com
 * OPTIONS: 
 */
#define	__MIG_check__Reply__shared_dns_info_subsystem__ 1
#define	__NDR_convert__Reply__shared_dns_info_subsystem__ 1
#define	__NDR_convert__mig_reply_error_subsystem__ 1

#include "shared_dns_info.h"


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
#if __MIG_check__Reply__shared_dns_info_subsystem__
#if !defined(__MIG_check__Reply__shared_dns_infoGet_t__defined)
#define __MIG_check__Reply__shared_dns_infoGet_t__defined
#ifndef __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined
#if	defined(__NDR_convert__int_rep__shared_dns_info__dnsDataOut_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__int_rep__shared_dns_info__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__int_rep__dnsDataOut_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__int_rep__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined */


#ifndef __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined
#if	defined(__NDR_convert__int_rep__shared_dns_info__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt(a, f) \
	__NDR_convert__int_rep__shared_dns_info__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__mach_msg_type_number_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt(a, f) \
	__NDR_convert__int_rep__mach_msg_type_number_t((mach_msg_type_number_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined */


#ifndef __NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined
#if	defined(__NDR_convert__char_rep__shared_dns_info__dnsDataOut_t__defined)
#define	__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__char_rep__shared_dns_info__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__char_rep__dnsDataOut_t__defined)
#define	__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__char_rep__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined */



#ifndef __NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined
#if	defined(__NDR_convert__float_rep__shared_dns_info__dnsDataOut_t__defined)
#define	__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__float_rep__shared_dns_info__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#elif	defined(__NDR_convert__float_rep__dnsDataOut_t__defined)
#define	__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined
#define	__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data(a, f, c) \
	__NDR_convert__float_rep__dnsDataOut_t((dnsDataOut_t *)(a), f, c)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined */




mig_internal kern_return_t __MIG_check__Reply__shared_dns_infoGet_t(__Reply__shared_dns_infoGet_t *Out0P)
{

	typedef __Reply__shared_dns_infoGet_t __Reply;
	boolean_t msgh_simple;
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 21100) {
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

#if	defined(__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined) || \
	defined(__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep) {
#if defined(__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined)
		__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt(&Out0P->dataCnt, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__dataCnt__defined */
#if defined(__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined)
		__NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data((dnsDataOut_t)(Out0P->data.address), Out0P->NDR.int_rep, Out0P->dataCnt);
#endif /* __NDR_convert__int_rep__Reply__shared_dns_infoGet_t__data__defined */
	}
#endif	/* defined(__NDR_convert__int_rep...) */

#if	defined(__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined) || \
	0
	if (Out0P->NDR.char_rep != NDR_record.char_rep) {
#if defined(__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined)
		__NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data((dnsDataOut_t)(Out0P->data.address), Out0P->NDR.char_rep, Out0P->dataCnt);
#endif /* __NDR_convert__char_rep__Reply__shared_dns_infoGet_t__data__defined */
	}
#endif	/* defined(__NDR_convert__char_rep...) */

#if	defined(__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined) || \
	0
	if (Out0P->NDR.float_rep != NDR_record.float_rep) {
#if defined(__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined)
		__NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data((dnsDataOut_t)(Out0P->data.address), Out0P->NDR.float_rep, Out0P->dataCnt);
#endif /* __NDR_convert__float_rep__Reply__shared_dns_infoGet_t__data__defined */
	}
#endif	/* defined(__NDR_convert__float_rep...) */

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__shared_dns_infoGet_t__defined) */
#endif /* __MIG_check__Reply__shared_dns_info_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine shared_dns_infoGet */
mig_external kern_return_t shared_dns_infoGet
(
	mach_port_t server,
	dnsDataOut_t *data,
	mach_msg_type_number_t *dataCnt
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

#ifdef	__MIG_check__Reply__shared_dns_infoGet_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__shared_dns_infoGet_t__defined */

	__DeclareSendRpc(21000, "shared_dns_infoGet")

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 21000;

	__BeforeSendRpc(21000, "shared_dns_infoGet")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(21000, "shared_dns_infoGet")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__shared_dns_infoGet_t__defined)
	check_result = __MIG_check__Reply__shared_dns_infoGet_t((__Reply__shared_dns_infoGet_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__shared_dns_infoGet_t__defined) */

	*data = (dnsDataOut_t)(Out0P->data.address);
	*dataCnt = Out0P->dataCnt;

	return KERN_SUCCESS;
    }
}

#if ( __MigTypeCheck || __NDR_convert__ )
#if __MIG_check__Reply__shared_dns_info_subsystem__
#if !defined(__MIG_check__Reply__shared_dns_infoSet_t__defined)
#define __MIG_check__Reply__shared_dns_infoSet_t__defined
#ifndef __NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined
#if	defined(__NDR_convert__int_rep__shared_dns_info__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode(a, f) \
	__NDR_convert__int_rep__shared_dns_info__kern_return_t((kern_return_t *)(a), f)
#elif	defined(__NDR_convert__int_rep__kern_return_t__defined)
#define	__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined
#define	__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode(a, f) \
	__NDR_convert__int_rep__kern_return_t((kern_return_t *)(a), f)
#endif /* defined(__NDR_convert__*__defined) */
#endif /* __NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined */





mig_internal kern_return_t __MIG_check__Reply__shared_dns_infoSet_t(__Reply__shared_dns_infoSet_t *Out0P)
{

	typedef __Reply__shared_dns_infoSet_t __Reply;
	if (Out0P->Head.msgh_id != 21101) {
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

#if defined(__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined)
	if (Out0P->NDR.int_rep != NDR_record.int_rep)
		__NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode(&Out0P->RetCode, Out0P->NDR.int_rep);
#endif	/* __NDR_convert__int_rep__Reply__shared_dns_infoSet_t__RetCode__defined */
	{		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__shared_dns_infoSet_t__defined) */
#endif /* __MIG_check__Reply__shared_dns_info_subsystem__ */
#endif /* ( __MigTypeCheck || __NDR_convert__ ) */


/* Routine shared_dns_infoSet */
mig_external kern_return_t shared_dns_infoSet
(
	mach_port_t server,
	dnsData_t data,
	mach_msg_type_number_t dataCnt
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
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
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

#ifdef	__MIG_check__Reply__shared_dns_infoSet_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__shared_dns_infoSet_t__defined */

	__DeclareSendRpc(21001, "shared_dns_infoSet")

#if	UseStaticTemplates
	const static mach_msg_ool_descriptor_t dataTemplate = {
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
	InP->data = dataTemplate;
	InP->data.address = (void *)(data);
	InP->data.size = dataCnt;
#else	/* UseStaticTemplates */
	InP->data.address = (void *)(data);
	InP->data.size = dataCnt;
	InP->data.deallocate =  FALSE;
	InP->data.copy = MACH_MSG_VIRTUAL_COPY;
	InP->data.type = MACH_MSG_OOL_DESCRIPTOR;
#endif	/* UseStaticTemplates */

	InP->NDR = NDR_record;

	InP->dataCnt = dataCnt;

	InP->Head.msgh_bits = MACH_MSGH_BITS_COMPLEX|
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = server;
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_id = 21001;

	__BeforeSendRpc(21001, "shared_dns_infoSet")
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
	__AfterSendRpc(21001, "shared_dns_infoSet")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__shared_dns_infoSet_t__defined)
	check_result = __MIG_check__Reply__shared_dns_infoSet_t((__Reply__shared_dns_infoSet_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS)
		{ return check_result; }
#endif	/* defined(__MIG_check__Reply__shared_dns_infoSet_t__defined) */

	return KERN_SUCCESS;
    }
}
