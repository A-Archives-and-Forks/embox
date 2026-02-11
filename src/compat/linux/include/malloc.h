/**
 * @file
 * @brief
 *
 * @date 02.12.2025
 * @author Aleksey Zhmulin
 */

#ifndef COMPAT_LINUX_MALLOC_H_
#define COMPAT_LINUX_MALLOC_H_

#include <stdlib.h>

#include <sys/cdefs.h>


__BEGIN_DECLS

extern int malloc_trim(size_t pad);

__END_DECLS

#endif /* COMPAT_LINUX_MALLOC_H_ */
