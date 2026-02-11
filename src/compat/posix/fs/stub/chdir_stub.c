/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <unistd.h>

#include <util/log.h>

int chdir(const char *path) {
	log_warning(">>> %s", __func__);
	return -1;
}
