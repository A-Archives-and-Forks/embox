/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <signal.h>

int sigsuspend(const sigset_t *sigmask) {
	(void) sigmask;

	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
