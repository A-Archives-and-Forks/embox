/**
 * @file
 *
 * @date Jun 7, 2018
 * @author Anton Bondarev
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "kernel/time/time.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: clock_nanosleep USEC\n");
		return EINVAL;
	}
	int usec = atoi(argv[1]);
	struct timespec now, time_to_wake, time_to_sleep, diff;

	time_to_sleep = ns_to_timespec(usec * NSEC_PER_USEC);

	clock_gettime(CLOCK_MONOTONIC, &now);
	time_to_wake = timespec_add(now, time_to_sleep);
	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &time_to_wake, NULL);
	clock_gettime(CLOCK_MONOTONIC, &now);
	printf("Must wake at %d sec %d nsec\n", time_to_wake.tv_sec, time_to_wake.tv_nsec);
	printf("Actual wakeup time: %d sec %d nsec\n", now.tv_sec, now.tv_nsec);

	diff = timespec_sub(now, time_to_wake);
	printf("Diff: %d sec %d nsec\n",diff.tv_sec,
	    diff.tv_nsec);
	return 0;
}
