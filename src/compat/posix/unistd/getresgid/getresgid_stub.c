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

int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
	(void) rgid;
	(void) egid;
	(void) sgid;
	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
	(void) rgid;
	(void) egid;
	(void) sgid;
	log_debug("stub %s()", __func__);
	return SET_ERRNO(-ENOSYS);
}
