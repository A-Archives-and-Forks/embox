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
	log_debug("stub for %s(%d, )", __func__, fd);
	return SET_ERRNO(-ENOSYS);
}

int futimesat(int dirfd, const char *path,
				const struct timeval times[2]) {
	log_debug("stub for %s(%d, )", __func__, dirfd);
	return SET_ERRNO(-ENOSYS);
}