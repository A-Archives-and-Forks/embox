/*
 * sched_posix.c
 *
 *  Created on: 5 feb. 2013
 *      Author: fsulima
 */
#include <util/log.h>

#include <errno.h>
#include <sched.h>
#include <pthread.h>

#include <kernel/sched.h>

int sched_yield(void) {
	sched_post_switch();
	return 0;
}

int sched_get_priority_min(int policy) {
	switch(policy) {
		case SCHED_OTHER:
			return SCHED_OTHER_PRIORITY_MIN;
		case SCHED_FIFO:
		case SCHED_RR:
			return SCHED_RT_PRIORITY_MIN;
		default:
			return SET_ERRNO(-EINVAL);
	}	
}

int sched_get_priority_max(int policy) {
	switch(policy) {
		case SCHED_OTHER:
			return SCHED_OTHER_PRIORITY_MAX;
		case SCHED_FIFO:
		case SCHED_RR:
			return SCHED_RT_PRIORITY_MAX;
		default:
			return SET_ERRNO(-EINVAL);
	}
}

int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param) {
	if (pid == 0) {
		pthread_setschedparam(pthread_self(), policy, param);
	} else {
		log_debug("stub %s(%ld, %d, )", __func__, (long) pid, policy);
	}

	return 0;
}

