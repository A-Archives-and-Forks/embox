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

int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag) {
	(void) fd;
	(void) path;
	(void) owner;
	(void) group;
	(void) flag;
	log_debug("stub fchownat(%d, %s,)", fd, path);
	return SET_ERRNO(-ENOSYS);
}
