/**
 * @file
 * @brief
 *
 * @date 11.12.2013
 * @author Anton Kozlov
 */

#include <sys/types.h>
#include <unistd.h>

#include <kernel/task.h>

pid_t getpid(void) {
	return task_get_id(task_self());
}
