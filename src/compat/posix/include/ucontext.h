/**
 * @file
 *
 * @date: Jul 18, 2022
 * @author Anton Bondarev
 */

#ifndef SRC_COMPAT_POSIX_INCLUDE_UCONTEXT
#define SRC_COMPAT_POSIX_INCLUDE_UCONTEXT

#include <defines/sigset_t_define.h>
#include <defines/stack_t_define.h>

#include <defines/mcontext_t_define.h>

#include <defines/ucontext_t_define.h>

#include <sys/cdefs.h>


__BEGIN_DECLS

/* stubs */
extern void makecontext(ucontext_t *ucp, void (*func)(),
       int argc, ...);
extern int swapcontext(ucontext_t *restrict oucp,
       const ucontext_t *restrict ucp);

__END_DECLS

#endif /* SRC_COMPAT_POSIX_INCLUDE_UCONTEXT */
