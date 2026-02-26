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
	int usec = 100000;
	struct timespec start, end, time_to_wake, time_to_sleep, diff;
	int i = 10;

	if (argc > 1 ) {
		usec = atoi(argv[1]);
	}

	if (argc > 2 ) {
		usec = atoi(argv[2]);
	}

	time_to_sleep = ns_to_timespec(usec * NSEC_PER_USEC);

	for (; i >= 0; i --) {
		clock_gettime(CLOCK_MONOTONIC, &start);
		time_to_wake = timespec_add(start, time_to_sleep);
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &time_to_wake, NULL);
		clock_gettime(CLOCK_MONOTONIC, &end);

		printf("Start time: %ld sec %ld nsec\n", start.tv_sec, start.tv_nsec);
		printf("Must wake at %ld sec %ld nsec\n", time_to_wake.tv_sec,
												time_to_wake.tv_nsec);
		printf("Actual wakeup time: %ld sec %ld nsec\n", end.tv_sec,
												end.tv_nsec);

		diff = timespec_sub(end, time_to_wake);
		printf("*** Diff: %ld sec %ld nsec\n\n",diff.tv_sec, diff.tv_nsec);
	}
	return 0;
}
