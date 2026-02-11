/**
 * @brief
 *
 * @date 12.02.24
 * @author Aleksey Zhmulin
 */

#include <stddef.h>
#include <sys/xattr.h>

#include <util/log.h>

int getxattr(const char *path, const char *name, char *value, size_t size) {
	log_warning(">>> %s", __func__);
	return -1;
}

int setxattr(const char *path, const char *name, const char *value, size_t size,
    int flags) {
	log_warning(">>> %s", __func__);
	return -1;
}

int listxattr(const char *path, char *list, size_t size) {
	log_warning(">>> %s", __func__);
	return -1;
}

int fsetxattr(int fd, const char *name, const char *value, size_t size, int flags) {
	log_warning(">>> %s", __func__);
	return -1;
}

int fgetxattr(int fd, const char *name, void *value, size_t size) {
	log_warning(">>> %s", __func__);
	return -1;
}

int flistxattr(int fd, char *list, size_t size) {
	log_warning(">>> %s", __func__);
	return -1;
}
