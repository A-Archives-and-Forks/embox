/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <sys/stat.h>

#include <util/log.h>

int chmod(const char *path, mode_t mode) {
	log_warning(">>> %s", __func__);
	return -1;
}
