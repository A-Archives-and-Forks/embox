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

int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid){
	(void) ruid;
	(void) euid;
	(void) suid;
	log_debug("stub getresuid");
	return SET_ERRNO(-ENOSYS);
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid){
	(void) ruid;
	(void) euid;
	(void) suid;
	log_debug("stub setresuid");
	return SET_ERRNO(-ENOSYS);
}
