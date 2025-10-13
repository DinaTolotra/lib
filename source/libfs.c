#include "libfs.h"

int fs_opne_r(char *file) {
	int fd;

	fd = open(file, O_RDONLY);
	return fd;
}

int fs_opne_w(char *file) {
	int fd;

	fd = open(file, O_WRONLY);
	return fd;
}

int fs_close(int fd) {
	int ret;

	ret = close(fd);
	return ret;
}
