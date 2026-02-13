/**
 * @file
 *
 * @date 10.03.2026
 * @author Dmitry Pilyuk
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <embox/test.h>

#include "framework/test/assert.h"
#include "sys/time.h"

EMBOX_TEST_SUITE("time/nanosleep*");

#define SLEEPNSEC 5000000

TEST_CASE("clock_nanosleep with reltime") {
	struct timespec time_to_sleep, start_time, end_time, slept;

	if (clock_gettime(CLOCK_MONOTONIC, &start_time) != 0) {
		perror("clock_gettime() did not return success\n");
		return;
	}

	time_to_sleep.tv_sec = 0;
	time_to_sleep.tv_nsec = SLEEPNSEC;
	if (clock_nanosleep(CLOCK_MONOTONIC, 0, &time_to_sleep, NULL) != 0) {
		printf("clock_nanosleep() did not return success\n");
		return;
	}

	if (clock_gettime(CLOCK_REALTIME, &end_time) == -1) {
		perror("Error in clock_gettime()\n");
		return;
	}

	timespecsub(&end_time, &start_time, &slept);
	test_assert(abs(slept.tv_nsec - SLEEPNSEC) <= SLEEPNSEC / 10);
}

// TEST_CASE("clock_nanosleep with abstime") {
// 	struct timespec time_to_sleep, start_time, wakeup_time, end_time;

// 	if (clock_gettime(CLOCK_MONOTONIC, &start_time) != 0) {
// 		perror("clock_gettime() did not return success\n");
// 		return;
// 	}
// 	time_to_sleep.tv_sec = 0;
// 	time_to_sleep.tv_nsec = SLEEPNSEC;

// 	timespecadd(&start_time, &time_to_sleep, &wakeup_time);

// 	if (clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &wakeup_time, NULL) != 0) {
// 		printf("clock_nanosleep() did not return success\n");
// 		return;
// 	}

// 	if (clock_gettime(CLOCK_REALTIME, &end_time) == -1) {
// 		perror("Error in clock_gettime()\n");
// 		return;
// 	}

// 	// bool cond = (end_time.tv_sec > wakeup_time.tv_sec) || (end_time.tv_sec == wakeup_time.tv_sec && end_time.tv_nsec > wakeup_time.tv_nsec)
// 	test_assert(1!=1);
// }
