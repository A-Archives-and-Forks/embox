/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <stdio.h>

extern int renameat(int oldfd, const char *old, int newfd, const char *new); {
	(void) oldfd;
	(void) old;
	(void) newfd;
	(void) new;

	log_debug("stub %s(%d, %s, %d, %s)", __func__, oldfd, old, newfd, new);
	return SET_ERRNO(-ENOSYS);
}
