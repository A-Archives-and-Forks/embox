/**
 * @file
 *
 * @date 10.03.2026
 * @author Dmitry Pilyuk
 */

#include <stdio.h>
#include <time.h>

#include <embox/test.h>

#include "framework/test/assert.h"
#include "sys/time.h"

EMBOX_TEST_SUITE("time/nanosleep*");

#define SLEEPNSEC 3000000

TEST_CASE("time/call timer_handler") {
	struct timespec time_to_sleep, start_time, end_time, slept;
	// int slepts = 0, sleptns = 0;

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

	test_assert((slept.tv_sec > 0) || (slept.tv_nsec > SLEEPNSEC));
}
