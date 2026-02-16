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
#include <sys/time.h>

int lutimes(const char *path, const struct timeval times[2]) {
	log_debug("path - %s", path);
	return SET_ERRNO(-ENOSYS);
}