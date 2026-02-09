/**
 * @file
 *
 * @date: Feb 07, 2026
 * @author Anton Bondarev
 */
#include <errno.h>
#include <signal.h>

#include <kernel/task.h>
#include <kernel/thread/thread_sched_wait.h>
#include <kernel/sched.h>

#include <module/embox/kernel/task/resource/timer_table.h>

int sigwait(const sigset_t *set, int *sig) {
	struct task_resource_timer_desc *desc;
	int i;
	int signo = -1;

	for (i = 0; i < MODOPS_TASK_TIMER_MAX; i ++) {
		desc = task_resource_timer_table_get(task_self(), i);
		if (desc == NULL) {
			continue;
		}
		signo = desc->sigevent.sigev_signo;
		if (1 == sigismember(set, signo)) {
			break;
		}
	}
	if (signo == -1) {
		return -EINVAL;
	}

	//SCHED_WAIT(desc->trtd_raised);
	while (!desc->trtd_raised) {
		//sleep(0);
	}

	*sig = signo;

	return 0;
}
