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

int fdatasync(int fildes) {
	log_debug("fildes - %d", fildes);
	SET_ERRNO(-ENOSYS);
	return -1;
}