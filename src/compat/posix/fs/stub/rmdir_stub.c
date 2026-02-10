/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <unistd.h>

#include <util/log.h>

int rmdir(const char *pathname) {
	log_warning(">>> %s", __func__);
	return -1;
}
