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

int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags){
	log_debug("fd - %d, path(%s) mode - %d\n", dirfd, pathname, mode);
	SET_ERRNO(-ENOSYS);
	return -1;
}