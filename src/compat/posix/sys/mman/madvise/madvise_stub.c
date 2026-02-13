/**
 * @file
 * @brief A stub for madvise()
 * @author Anton Bondarev
 * @version
 * @date 13.17.2026
 */

#include <util/log.h>

#include <errno.h>
#include <sys/mman.h>
#include <stddef.h>

int madvise(void *start, size_t length, int advice) {
	log_debug("stub madvise(%p, %zu, %d)", start, length, advice);
	return SET_ERRNO(-ENOSYS);
}
