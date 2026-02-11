/**
 * @file
 * @brief
 *
 * @date 11.03.13
 * @author Ilia Vaprol
 */

#include <errno.h>
#include <sys/resource.h>
#include <sys/types.h>

#include <kernel/task.h>

int getpriority(int which, id_t who) {
	struct task *task;

	if (which != PRIO_PROCESS) {
		return SET_ERRNO(EINVAL);
	}

	task = task_find(who);
	if (!task) {
		return SET_ERRNO(ESRCH);
	}

	return task_get_priority(task);
}
