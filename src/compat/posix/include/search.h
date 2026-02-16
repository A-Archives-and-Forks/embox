
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

struct entry {
    char    *key;
    void    *data;
};

typedef struct entry ENTRY;

typedef enum { FIND, ENTER } ACTION;

typedef enum { preorder, postorder, endorder, leaf } VISIT;

extern int    hcreate(size_t);
extern void   hdestroy(void);
extern ENTRY *hsearch(ENTRY, ACTION);
extern void   insque(void *, void *);
extern void   remque(void *);

extern void *lsearch(const void *key, void *base, size_t *nelp, size_t width,
                    int (*compar)(const void *, const void *));
extern void *lfind(const void *key, const void *base, size_t *nelp,
                    size_t width, int (*compar)(const void *, const void *));

extern void *tdelete(const void */*restrict */ key, void **/*restrict*/ rootp,
                    int(*compar)(const void *, const void *));
extern void *tfind(const void *key, void *const *rootp,
                    int(*compar)(const void *, const void *));
extern void *tsearch(const void *key, void **rootp,
                    int (*compar)(const void *, const void *));

extern void twalk(const void *root, void (*action)(const void *, VISIT , int));

__END_DECLS

#endif /* COMPAT_POSIX_SEARCH_H_ */