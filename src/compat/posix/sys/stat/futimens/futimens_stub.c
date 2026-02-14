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
#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2]) {
	log_debug("stub futimens(%d,)", fd);
	return SET_ERRNO(-ENOSYS);
}
