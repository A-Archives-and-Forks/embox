/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>

#include <unistd.h>

int symlink(const char *path1, const char *path2) {
	log_debug("stub %s(%s, %s)", __func__, path1, path2);
	return SET_ERRNO(-ENOSYS);
}

int symlinkat(const char *path1, int fd, const char *path2) {
	log_debug("stub %s(%s, %d, %s)", __func__, path1, fd, path2);
	return SET_ERRNO(-ENOSYS);
}
