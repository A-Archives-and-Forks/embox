/**
 * @file
 *
 * @date Sep 26, 2020
 * @author Anton Bondarev
 */

#include <errno.h>
#include <sys/resource.h>

#include <kernel/task.h>

int setrlimit(int resource, const struct rlimit *rlp) {
	switch (resource) {
	case RLIMIT_STACK:
		task_setrlim_stack_size(task_self(), rlp->rlim_cur);
		break;
	default:
		return SET_ERRNO(EINVAL);
	}

	return 0;
}
