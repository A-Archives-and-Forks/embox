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

int symlink(const char *path1, const char *path2) {
	SET_ERRNO(-ENOSYS);
	return -1;
}