/**
 * @file
 * @brief
 *
 * @author Aleksey Zhmulin
 * @date 15.05.23
 */

#include <stddef.h>
#include <sys/mman.h>

#include <util/log.h>

int mprotect(void *addr, size_t len, int prot) {
	log_debug(">>> %s", __func__);
	return -1;
}
