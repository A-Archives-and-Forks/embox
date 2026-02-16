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

 pid_t getsid(pid_t pid) {
	log_debug("stub %s(%d)", __func__, pid);
	return SET_ERRNO(-ENOSYS);
}