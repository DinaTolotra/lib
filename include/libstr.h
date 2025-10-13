#ifndef LIBSTR_H
#define LIBSTR_H

#include <stdlib.h>

int char_is_lower(char c);
int char_is_upper(char c);
int char_is_alpha(char c);
int char_is_num(char c);
int char_is_space(char c);
int char_is_printable(char c);

int str_len(char *str);
char *str_dup(char *str);
int str_to_nb(char *str);
char *str_from_nb(int nb);

int str_to_nb_base(char *str, char *base);
char *str_from_nb_base(int nb, char *base);

#endif // LIBSTR_H
