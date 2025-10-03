#include "libio.h"

#include <unistd.h>

int io_put_char(int fd, char c) {
  int count;

  count = write(fd, &c, 1);
  return count;
}

int io_put_str(int fd, char *str) {
  int index; // also count of character

  index = 0;
  while (str[index]) {
    io_put_char(fd, str[index]);
    index++;
  }
  return index;
}

int io_put_nb(int fd, int nb) {
  long lnb;
  int count;

  lnb = nb;
  count = 0;
  if (lnb < 0 ) {
    io_put_char(fd, '-');
    lnb = -lnb;
  }
  if (nb >= 10)
    count = io_put_nb(fd, (nb / 10));
  io_put_char(fd, ((nb % 10) + '0'));
  count++;
  return count;
}
