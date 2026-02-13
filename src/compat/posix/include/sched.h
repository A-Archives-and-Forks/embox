/**
 * @file
 *
 * @brief POSIX (REALTIME) execution scheduling
 *
 * @details http://pubs.opengroup.org/onlinepubs/7908799/xsh/sched.h.html
 *
 * @date Jan 17, 2013
 * @author: Anton Bondarev
 */

#ifndef POSIX_SCHED_H_
#define POSIX_SCHED_H_

#include <limits.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <time.h>

/**
 * Scheduling policies
 * TODO SCHED_FIFO and SCHED_RR may have priority more or equal 200
 */
#define SCHED_OTHER 0 /* Another scheduling policy.*/
#define SCHED_FIFO  1 /* First in-first out (FIFO) scheduling policy*/
#define SCHED_RR    2 /* Round robin scheduling policy. */

#define CPU_ZERO(s) \
	do {            \
		*(s) = 0;   \
	} while (0)

#define CPU_SET(c, s)        \
	do {                     \
		*(s) |= (1u << (c)); \
	} while (0)

#define CPU_CLR(c, s)         \
	do {                      \
		*(s) &= ~(1u << (c)); \
	} while (0)

#define CPU_AND(d, s1, s2)    \
	do {                      \
		*(d) = *(s1) & *(s2); \
	} while (0)

#define CPU_OR(d, s1, s2)     \
	do {                      \
		*(d) = *(s1) | *(s2); \
	} while (0)

#define CPU_XOR(d, s1, s2)    \
	do {                      \
		*(d) = *(s1) ^ *(s2); \
	} while (0)

#define CPU_SETSIZE             WORD_BIT
#define CPU_ISSET(c, s)         ((*(s) & (1u << (c))) != 0)
#define CPU_COUNT(s)            __builtin_popcount(*s)
#define CPU_EQUAL(s1, s2)       (*(s1) == *(s2))
#define CPU_ALLOC(n)            (cpu_set_t *)malloc(sizeof(cpu_set_t))
#define CPU_FREE(s)             free(s)
#define CPU_ALLOC_SIZE(n)       sizeof(cpu_set_t)
#define CPU_ZERO_S(n, s)        CPU_ZERO(s)
#define CPU_SET_S(c, n, s)      CPU_SET(c, s)
#define CPU_CLR_S(c, n, s)      CPU_CLR(c, s)
#define CPU_ISSET_S(c, n, s)    CPU_ISSET(c, s)
#define CPU_COUNT_S(n, s)       CPU_COUNT(s)
#define CPU_AND_S(n, d, s1, s2) CPU_AND(d, s1, s2)
#define CPU_OR_S(n, d, s1, s2)  CPU_OR(d, s1, s2)
#define CPU_XOR_S(n, d, s1, s2) CPU_XOR(d, s1, s2)
#define CPU_EQUAL_S(n, s1, s2)  CPU_EQUAL(s1, s2)

struct sched_param {
	int sched_priority; /**< Process or thread execution scheduling priority. */
	                    /*
	In addition, if _POSIX_SPORADIC_SERVER or _POSIX_THREAD_SPORADIC_SERVER is
	defined, the sched_param structure defined in <sched.h> shall contain the
	following members in addition to those specified above:

	int             sched_ss_low_priority Low scheduling priority for
	                                      sporadic server.
	struct timespec sched_ss_repl_period  Replenishment period for
	                                      sporadic server.
	struct timespec sched_ss_init_budget  Initial budget for sporadic server.
	int             sched_ss_max_repl     Maximum pending replenishments for
	                                      sporadic server.
	*/
};

__BEGIN_DECLS

/**
 * sched_get_priority_max, get max priority  limit
 */
extern int sched_get_priority_max(int);

/**
 * sched_get_priority_min - get min priority limits
 */
extern int sched_get_priority_min(int);

/**
 * get scheduling parameters
 */
extern int sched_getparam(pid_t, struct sched_param *);

/**
 * get scheduling policy
 */
extern int sched_getscheduler(pid_t);

/**
 * get execution time limits
 */
extern int sched_rr_get_interval(pid_t, struct timespec *);

/**
 * set scheduling parameters
 */
extern int sched_setparam(pid_t, const struct sched_param *);

/**
 * set scheduling policy and parameters
 */
extern int sched_setscheduler(pid_t, int, const struct sched_param *);

/**
 *  yield processor
 */
extern int sched_yield(void);

typedef unsigned int cpu_set_t;

extern int sched_getcpu(void);

extern int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask);
extern int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);

/* stubs */
extern int unshare(int flags);

__END_DECLS

#endif /* POSIX_SCHED_H_ */
