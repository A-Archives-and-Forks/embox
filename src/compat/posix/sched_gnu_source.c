/**
 * @file
 *
 * @date 5 feb. 2013
 * @author Anton Bondarev
 */

#include <sched.h>

#include <kernel/sched.h>

#include <hal/cpu.h>

int sched_getcpu(void) {
	uint32_t cpuid = cpu_get_id();
	return cpuid;
}

int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask) {
	return 0;
}
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask) {
	return 0;
}