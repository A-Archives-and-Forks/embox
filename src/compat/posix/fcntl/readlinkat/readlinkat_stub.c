/**
 * @file
 * @brief
 *
 * @author  Anton Kozlov
 * @date    16.04.2014
 */

#include <util/log.h>

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <utime.h>

ssize_t readlinkat(int fd, const char *path, char *buf,
		size_t bufsize) {
	log_debug(">>> %s %d %s %s %zu\n", __func__, fd, path, buf,
			bufsize);
	return SET_ERRNO(ENOSYS);
}

