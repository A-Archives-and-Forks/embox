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

int sigaltstack(const stack_t *ss, stack_t *oss) {
	(void) ss;
	(void) oss;

	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
