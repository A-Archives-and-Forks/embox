/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <unistd.h>

#include <util/log.h>

int chown(const char *path, uid_t owner_id, gid_t group_id) {
	log_warning(">>> %s", __func__);
	return -1;
}

__strong_alias(lchown, chown);
