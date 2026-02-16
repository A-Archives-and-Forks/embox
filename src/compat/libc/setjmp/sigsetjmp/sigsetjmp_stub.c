/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <setjmp.h>

int sigsetjmp(sigjmp_buf env, int val) {
	log_debug("%s",__func__);
	return -1;
}