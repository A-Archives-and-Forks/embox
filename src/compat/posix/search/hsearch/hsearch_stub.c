/**
 * @file
 * @brief
 *
 * @date 12.02.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>
#include <stddef.h>
#include <search.h>

int hcreate(size_t) {
    log_debug("stub %s()", __func__);
    return 0;
}

void hdestroy(void) {
    log_debug("stub %s()", __func__);
}

ENTRY *hsearch(ENTRY, ACTION) {
    log_debug("stub %s()", __func__);
    return NULL;
}
