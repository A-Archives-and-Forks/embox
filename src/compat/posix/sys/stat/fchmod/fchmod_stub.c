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

int fchmod(int fildes, mode_t mode) {
	log_debug("fd - %d, mode - %d\n", fildes, mode);
	SET_ERRNO(-ENOSYS);
	return -1;
}