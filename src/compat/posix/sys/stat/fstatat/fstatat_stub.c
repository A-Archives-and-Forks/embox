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

extern int fstatat(int fd, const char */*restrict*/ path,
       					struct stat */* restrict */ buf, int flag); {
	log_debug("fd - %d", fd);
	SET_ERRNO(-ENOSYS);
	return -1;
}