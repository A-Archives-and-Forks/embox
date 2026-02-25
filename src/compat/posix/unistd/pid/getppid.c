/**
 * @file
 * @brief
 *
 * @date 21.02.26
 * @author Aleksey Zhmulin
 */

#include <sys/types.h>
#include <unistd.h>

#include <kernel/task.h>

pid_t getppid(void) {
	struct task *t;

	t = task_get_parent(task_self());
	if (t == NULL) {
		return 1;
	}

	return task_get_id(t);
}
