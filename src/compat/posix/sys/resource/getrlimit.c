/**
 * @file
 *
 * @date Sep 26, 2020
 * @author Anton Bondarev
 */

#include <errno.h>
#include <string.h>
#include <sys/resource.h>

#include <kernel/task.h>

int getrlimit(int resource, struct rlimit *rlp) {
	memset(rlp, 0, sizeof(struct rlimit));

	switch (resource) {
	case RLIMIT_STACK:
		rlp->rlim_cur = task_getrlim_stack_size(task_self());
		rlp->rlim_max = RLIM_INFINITY;
		break;
	default:
		return SET_ERRNO(EINVAL);
	}

	return 0;
}
