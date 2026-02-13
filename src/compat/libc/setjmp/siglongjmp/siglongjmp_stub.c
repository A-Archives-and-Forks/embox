/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <setjmp.h>

void siglongjmp(sigjmp_buf env, int val) {
	log_debug("%s",__func__);
}