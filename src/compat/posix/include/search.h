
/**
 * @file
 * @brief
 *
 * @author  Anton Bondarev
 * @date    11.02.2026
 */

#ifndef COMPAT_POSIX_SEARCH_H_
#define COMPAT_POSIX_SEARCH_H_

/* The size_t type shall be defined as described in <sys/types.h>. */
#include <sys/types.h>

#include <sys/cdefs.h>

__BEGIN_DECLS

extern void *lsearch(const void *key, void *base, size_t *nelp, size_t width,
                    int (*compar)(const void *, const void *));
extern void *lfind(const void *key, const void *base, size_t *nelp,
                    size_t width, int (*compar)(const void *, const void *));

__END_DECLS

#endif /* COMPAT_POSIX_SEARCH_H_ */