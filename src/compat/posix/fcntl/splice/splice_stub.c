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

ssize_t splice(int fd_in, off_t */*_Nullable */ off_in,
                      int fd_out, off_t */*_Nullable */ off_out,
                      size_t size, unsigned int flags) {

	log_debug(">>> %s %d %d %d %d %zu\n", __func__, fd_in, off_in, fd_out, 
									off_out, size);
	return SET_ERRNO(ENOSYS);
}

