#ifndef LIBFS_H
#define LIBFS_H

#include <unistd.h>
#include <fcntl.h>

int fs_opne_r(char *file);
int fs_opne_w(char *file);

int fs_close(int fd);

#endif // LIBFS_H
