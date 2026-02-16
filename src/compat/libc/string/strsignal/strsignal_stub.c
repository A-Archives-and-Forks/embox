/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <stddef.h>
#include <string.h>

char *strsignal(int signum) {
    log_debug("stub %s(%d)", __func__, signum);
    return NULL;
}