/**
 * @file
 * @brief
 *
 * @author  Anton Kozlov
 * @date    18.04.2014
 */

#include <util/log.h>

#include <errno.h>
#include <ucontext.h>

void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...) {
	log_debug("stub %s", __func__);
}

int swapcontext(ucontext_t *restrict oucp, const ucontext_t *restrict ucp) {
	log_debug("stub %s", __func__);
	return SET_ERRNO(ENOSYS);
}

int getcontext(ucontext_t *ucp) {
	log_debug("stub %s", __func__);
	return SET_ERRNO(ENOSYS);
}

int setcontext(const ucontext_t *ucp) {
	log_debug("stub %s", __func__);
	return SET_ERRNO(ENOSYS);
}
