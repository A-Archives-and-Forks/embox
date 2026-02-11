/**
 * @file
 * @brief
 *
 * @author  Anton Bondarev
 * @date    14.01.2026
 */

#include <embox/test.h>

#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

EMBOX_TEST_SUITE("signal/sigwait");
#if 1
TEST_CASE("signal/sigwait ") {
    sigset_t sigset;
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec ts;
    int sig = 0;

    sigemptyset(&sigset);
    sigaddset(&sigset, SIGRTMIN);
    pthread_sigmask(SIG_BLOCK, &sigset, NULL);

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    timer_create(CLOCK_REALTIME, &sev, &timerid);

    ts.it_value.tv_sec = 0;
    ts.it_value.tv_nsec = 100000000;
    ts.it_interval.tv_sec = 0;
    ts.it_interval.tv_nsec = 100000000;
    timer_settime(timerid, 0, &ts, NULL);

    sigwait(&sigset, &sig);

    test_assert(sig == SIGRTMIN);
    sigdelset(&sigset, SIGRTMIN);
}
#endif
