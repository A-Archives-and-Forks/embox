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

int sethostname(const char *name, size_t len)  {
	log_debug("stub %s(%s,)", __func__, name);
	return SET_ERRNO(-ENOSYS);
}