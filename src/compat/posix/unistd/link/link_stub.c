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

int link(const char *path1, const char *path2) {
	log_debug(">>> %s %s %s\n", __func__, oldpath, newpath);
	SET_ERRNO(-ENOSYS);
	return -1;
}
