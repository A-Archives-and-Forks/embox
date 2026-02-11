/**
 * @file
 * @brief
 *
 * @date 11.03.13
 * @author Ilia Vaprol
 */

#ifndef COMPAT_POSIX_SYS_RESOURCE_H_
#define COMPAT_POSIX_SYS_RESOURCE_H_

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/time.h>
#include <sys/types.h>

/* Values of the 'resource' arg of getrlimit() and setrlimit() */
#define RLIMIT_CORE    0  /* limit on size of core dump file */
#define RLIMIT_CPU     1  /* limit on CPU time per process */
#define RLIMIT_DATA    2  /* limit on data segment size */
#define RLIMIT_FSIZE   3  /* limit on file size */
#define RLIMIT_NOFILE  4  /* limit on number of open files */
#define RLIMIT_STACK   5  /* limit on stack size */
#define RLIMIT_AS      6  /* limit on address space size */
#define RLIMIT_MEMLOCK 7  /* limit on memory use */
#define RLIMIT_NICE    8  /* limit on nice level */
#define RLIMIT_RTPRIO  9  /* limit on RT tasks priority */
#define RLIMIT_RTTIME  10 /* limit on timeout for RT tasks in microseconds */

/* Values of the 'which' arg of getpriority() and setpriority() */
#define PRIO_PROCESS 0 /* 'who' arg is a process ID */
#define PRIO_PGRP    1 /* 'who' arg is a process group ID */
#define PRIO_USER    2 /* 'who' arg is a user ID */

/* Values of the 'who' arg of getrusage() */
#define RUSAGE_SELF     0 /* current process */
#define RUSAGE_CHILDREN 1 /* child processes */

/* Values of the 'rlim_t' type */
#define RLIM_INFINITY  UINT32_MAX    /* no limit */
#define RLIM_SAVED_MAX RLIM_INFINITY /* unrepresentable saved hard limit */
#define RLIM_SAVED_CUR RLIM_INFINITY /* unrepresentable saved soft limit */

typedef uint32_t rlim_t;

struct rlimit {
	rlim_t rlim_cur; /* Soft limit */
	rlim_t rlim_max; /* Hard limit (ceiling for rlim_cur) */
};

struct rusage {
	struct timeval ru_utime; /* user time used */
	struct timeval ru_stime; /* system time used */
	long ru_maxrss;          /* maximum resident set size */
	long ru_ixrss;           /* integral shared memory size */
	long ru_idrss;           /* integral unshared data size */
	long ru_isrss;           /* integral unshared stack size */
	long ru_minflt;          /* page reclaims */
	long ru_majflt;          /* page faults */
	long ru_nswap;           /* swaps */
	long ru_inblock;         /* block input operations */
	long ru_oublock;         /* block output operations */
	long ru_msgsnd;          /* messages sent */
	long ru_msgrcv;          /* messages received */
	long ru_nsignals;        /* signals received */
	long ru_nvcsw;           /* voluntary context switches */
	long ru_nivcsw;          /* involuntary context switches */
};

__BEGIN_DECLS

extern int getrlimit(int resource, struct rlimit *rlp);
extern int setrlimit(int resource, const struct rlimit *rlp);

extern int getpriority(int which, id_t who);
extern int setpriority(int which, id_t who, int value);

extern int getrusage(int who, struct rusage *r_usage);

__END_DECLS

#endif /* COMPAT_POSIX_SYS_RESOURCE_H_ */
