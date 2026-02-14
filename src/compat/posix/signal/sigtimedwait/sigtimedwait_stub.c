/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <signal.h>

int sigtimedwait(const sigset_t */*restrict */ set,
       siginfo_t */*restrict */info,
       const struct timespec */*restrict */timeout) {
	(void) set;
	(void) info;
	(void) timeout;

	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
