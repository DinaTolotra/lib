#ifndef LIBIO_H
#define LIBIO_H

#include <unistd.h>

int io_put_char(int fd, char c);
int io_put_str(int fd, char *str);
int io_put_nb(int fd, int nb);
int io_put_nb_base(int fd, int nb, char *base);

int io_get_char(int fd, char *c);
int io_get_str(int fd, char *str, int size);

#endif // LIBIO_H
