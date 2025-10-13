#include "libstr.h"

#include <stdlib.h>

void _reverse(char *str, int n);
int _find(char c, char* str);

void _reverse(char *str, int n) {
  int index;
  int r_index;
  char c;

  index = 0;
  r_index = n - 1;
  while (index < r_index) {
    c = str[index];
    str[index] = str[r_index];
    str[r_index] = c;
    r_index--;
    index++;
  }
}

int _find(char c, char* str) {
  int index;

  index = 0;
  while (str[index] && str[index] != c)
    index++;
  if (!str[index])
    index = -1;
  return index;
}

int char_is_lower(char c) {
  return (c >= 'a' && c <= 'z');
}

int char_is_upper(char c) {
  return (c >= 'A' && c <= 'Z');
}

int char_is_alpha(char c) {
  return (char_is_lower(c) || char_is_upper(c));
}

int char_is_num(char c) {
  return (c >= '0' && c <= '9');
}

int char_is_space(char c) {
  int is_space;

  is_space = (c == ' ') || (c == '\n') || (c == '\t');
  is_space = is_space || (c == '\r') || (c == '\v') || (c == '\f');
  return is_space;
}

int char_is_printable(char c) {
  return (c >= 32 && c <= 126);
}

int str_len(char *str) {
  int index;

  index = 0;
  while (str[index])
    index++;
  return index;
}

char *str_dup(char *str) {
  char *dup;
  int index;
  int len;

  index = 0;
  len = str_len(str);
  dup = malloc(sizeof(char) * (len + 1));
  while (str[index]) {
    dup[index] = str[index];
    index++;
  }
  dup[index] = 0;
  return dup;
}

int str_to_nb(char *str) {
  long lnb;
  int sign;
  int index;

  lnb = 0;
  index = 0;
  sign = 1;
  if (str[index] == '-' || str[index] == '+') {
    if (str[index] == '-')
      sign = -1;
    index++;
  }
  while (char_is_num(str[index])) {
    lnb = (lnb * 10) + (str[index] - '0');
    index++;
  }
  lnb = lnb * sign;
  return lnb;
}

char *str_from_nb(int nb) {
  char *str;
  long lnb;
  int index;
  int r_index;

  lnb = nb;
  index = 0;
  str = malloc(sizeof(char) * 12);
  str[0] = '0';
  if (lnb < 0) {
    str[index] = '-';
    str[1] = '0';
    index++;
  }
  r_index = index;
  str[index + 1] = 0;
  while (lnb > 0) {
    str[index] = ((lnb % 10) + '0');
    str[index + 1] = 0;
    lnb = lnb / 10;
    index++;
  }
  _reverse(&str[r_index], index);
  return str;
}

int str_to_nb_base(char *str, char *base) {
  long lnb;
  int sign;
  int index;
  int b_val;
  int val;

  lnb = 0;
  index = 0;
  sign = 1;
  b_val = str_len(base);
  if (str[index] == '-' || str[index] == '+') {
    if (str[index] == '-')
      sign = -1;
    index++;
  }
  val = _find(str[index], base);
  while (str[index] && val != -1) {
    lnb = (lnb * b_val) + val;
    val = _find(str[index], base);
    index++;
  }
  lnb = lnb * sign;
  return lnb;
}

char *str_from_nb_base(int nb, char *base) {
  char *str;
  long lnb;
  int b_val;
  int index;
  int r_index;

  lnb = nb;
  index = 0;
  b_val = str_len(base);
  str = malloc(sizeof(char) * 34);
  str[0] = base[0];
  if (lnb < 0) {
    str[index] = '-';
    str[1] = base[0];
    index++;
  }
  r_index = index;
  str[index + 1] = 0;
  while (lnb > 0) {
    str[index] = base[lnb % b_val];
    str[index + 1] = 0;
    lnb = lnb / b_val;
    index++;
  }
  _reverse(&str[r_index], index);
  return str;
}
