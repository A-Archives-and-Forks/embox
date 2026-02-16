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

int sigpending(sigset_t *set){
	(void) set;

	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
