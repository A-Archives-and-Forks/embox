/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int utimensat(int dirfd, const char *pathname,
              const struct timespec times[2], int flags) {
	log_debug("stub utimensat(%d, %s, )", dirfd, pathname);
	return SET_ERRNO(-ENOSYS);
}