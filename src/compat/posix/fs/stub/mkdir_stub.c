/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <sys/stat.h>
#include <sys/types.h>

#include <util/log.h>

int mkdir(const char *pathname, mode_t mode) {
	log_warning(">>> %s", __func__);
	return -1;
}
