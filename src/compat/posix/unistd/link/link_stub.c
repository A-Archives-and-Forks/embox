/**
 * @file
 * @brief
 *
 * @date 12.021.2026
 * @author Anton Bondarev
 */

#include <util/log.h>

#include <errno.h>

#include <unistd.h>

int link(const char *path1, const char *path2) {
	log_debug("stub %s(%s, %s)", __func__, path1, path2);
	return SET_ERRNO(-ENOSYS);
}


int linkat(int olddirfd, const char *oldpath,
           int newdirfd, const char *newpath, int flags) {
	log_debug("stub %s(%d, %s, %d, %s)", __func__, olddirfd, oldpath, newdirfd,
					newpath);
	return SET_ERRNO(-ENOSYS);
}