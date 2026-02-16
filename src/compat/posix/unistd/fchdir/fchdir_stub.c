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

int fchdir(int fildes)  {
	log_debug("stub %s(%d)", __func__, fildes);
	return SET_ERRNO(-ENOSYS);
}