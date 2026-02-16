/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <stddef.h>
#include <unistd.h>

char *ttyname(int fildes)  {
	log_debug("stub %s(%d)", __func__, fildes);
	SET_ERRNO(-ENOSYS);
	return NULL;
}