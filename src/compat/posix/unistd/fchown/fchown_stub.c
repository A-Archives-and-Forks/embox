/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>

#include <unistd.h>

int fchown(int fildes, uid_t owner, gid_t group) {
	log_debug("fildes - %d", fd);
	SET_ERRNO(-ENOSYS);
	return -1;
}