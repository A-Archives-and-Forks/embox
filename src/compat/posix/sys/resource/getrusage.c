/**
 * @file
 * @brief
 *
 * @author Aleksey Zhmulin
 * @date 28.02.23
 */

#include <errno.h>
#include <string.h>
#include <sys/resource.h>

int getrusage(int who, struct rusage *r_usage) {
	if (!r_usage) {
		return SET_ERRNO(EINVAL);
	}

	memset(r_usage, 0, sizeof(struct rusage));

	return 0;
}
