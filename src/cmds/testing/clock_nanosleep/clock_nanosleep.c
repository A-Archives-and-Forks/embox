/**
 * @file
 *
 * @date Jun 7, 2018
 * @author Anton Bondarev
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char **argv) {
	struct timespec now, timetowake;
	clock_gettime(CLOCK_MONOTONIC, &now);
	timetowake = now;
	timetowake.tv_sec += 1;
	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &timetowake, NULL);
	clock_gettime(CLOCK_MONOTONIC, &now);
	printf("Must wake at %d sec %d nsec\n", timetowake.tv_sec, timetowake.tv_nsec);
	printf("Actual wakeup time: %d sec %d nsec\n", now.tv_sec, now.tv_nsec);
	printf("Diff: %d sec %d nsec\n", now.tv_sec - timetowake.tv_sec,
	    now.tv_nsec - timetowake.tv_nsec);
	return 0;
}
