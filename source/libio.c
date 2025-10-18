#include "libio.h"

#include <unistd.h>

int _len(char *str);

int _len(char *str) {
  int index;

  index = 0;
  while (str[index])
    index++;
  return index;
}

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

int io_put_nstr(int fd, char *str, int n) {
  int index; // also count of character

  index = 0;
  while (str[index] && index < n) {
    io_put_char(fd, str[index]);
    index++;
  }
  return index;
}

int io_put_nb(int fd, int nb) {
  long lnb;
  int count;

  lnb = nb;
  count = 1;
  if (lnb < 0 ) {
    io_put_char(fd, '-');
    lnb = -lnb;
  }
  if (lnb >= 10)
    count += io_put_nb(fd, (nb / 10));
  io_put_char(fd, ((nb % 10) + '0'));
  return count;
}

int io_put_nb_base(int fd, int nb, char *base) {
  long lnb;
  int count;
  int bs_val;

  lnb = nb;
  count = 1;
  bs_val = _len(base);
  if (lnb < 0 ) {
    io_put_char(fd, '-');
    lnb = -lnb;
  }
  if (lnb >= bs_val)
    count += io_put_nb_base(fd, (nb / bs_val), base);
  io_put_char(fd, base[nb % bs_val]);
  return count;
}

int io_get_char(int fd, char *c) {
  int count;

  count = read(fd, c, 1);
  return count;
}

int io_get_str(int fd, char *str, int size) {
  int count;

  count = read(fd, str, size);
  return count;
}
