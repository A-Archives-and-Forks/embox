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

int sigwaitinfo(const sigset_t */*restrict*/ set,
       siginfo_t */*restrict*/ info) {
	(void) set;
	(void) info;

	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
