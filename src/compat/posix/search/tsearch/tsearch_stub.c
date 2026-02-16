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

void *tdelete(const void */*restrict */ key, void **/*restrict*/ rootp,
       int(*compar)(const void *, const void *)) {
	log_debug("stub %s()", __func__);
    return NULL;
}

void *tfind(const void *key, void *const *rootp,
       int(*compar)(const void *, const void *)) {
    log_debug("stub %s()", __func__);
    return NULL;
}

void *tsearch(const void *key, void **rootp,
       int (*compar)(const void *, const void *)) {
    log_debug("stub %s()", __func__);
    return NULL;
}

void twalk(const void *root, void (*action)(const void *, VISIT, int)) {
    log_debug("stub %s()", __func__);
}
