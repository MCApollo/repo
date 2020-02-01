#ifndef UCONTEXT_H
#define UCONTEXT_H	1

#define _GCC 1

#ifndef _GCC /* Apple stack_t, sigset_t */
#include <sys/_types/_sigset_t.h>
#include <sys/_types/_sigaltstack.h>
#else
/* Hack to use ours instead of Apple's */
#define _STRUCT_UCONTEXT 1
#define _SIGSET_T 1
#define _STRUCT_SIGALTSTACK struct sigaltstack
#define __ARM_MCONTEXT_H_ 1
#include <sys/cdefs.h>
#include <sys/_types/_size_t.h>
typedef struct
  {
    void *ss_sp;
    size_t ss_size;
    int ss_flags;
  } stack_t;

typedef unsigned long int __sigset_t;
typedef __sigset_t sigset_t;
#endif

typedef struct
  {
    unsigned long fault_address;
    unsigned long regs[31];
    unsigned long sp, pc, pstate;
    long double __reserved[256];
  } mcontext_t;

typedef struct ucontext_t
  {
    unsigned long uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    sigset_t uc_sigmask;
    mcontext_t uc_mcontext;
  } ucontext_t;

extern int getcontext (ucontext_t *__ucp);
extern int setcontext (const ucontext_t *__ucp);
extern int swapcontext (ucontext_t *__restrict __oucp,
			const ucontext_t *__restrict __ucp);
extern void makecontext (ucontext_t *__ucp, void (*__func) (void),
			 int __argc, ...);

#endif
