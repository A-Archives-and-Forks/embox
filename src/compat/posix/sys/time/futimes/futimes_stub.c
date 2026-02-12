/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>

int futimes(int fd, const struct timeval tv[2]) {
	log_debug("fd - %d\n", fd);
	SET_ERRNO(-ENOSYS);
	return -1;
}