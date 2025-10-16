# LIB
## Description
Yet an another personal library.
## Content
- libio: *ongoing*
- libstr: *ongoing*
- libnb: *comming soon*
- libfs: *ongoing*
### libio
- **Prefix**: io_
- **API**:
     - int io_put_char(int fd, char c);
     - int io_put_str(int fd, char *str);
     - int io_put_nb(int fd, int nb);
     - int io_put_nb_base(int fd, int nb, char *base);
     - int io_get_char(int fd, char *c);
     - int io_get_str(int fd, char *str, int size);
### libstr
- **Prefix**: char_, str_
- **API**:
     - int char_is_lower(char c);
     - int char_is_upper(char c);
     - int char_is_alpha(char c);
     - int char_is_num(char c);
     - int char_is_space(char c);
     - int char_is_printable(char c);
     - int str_len(char *str);
     - char *str_dup(char *str);
     - int str_to_nb(char *str);
     - char *str_from_nb(int nb);
     - int str_to_nb_base(char *str, char *base);
     - char *str_from_nb_base( - nb, char *base);
### libfs
- **Prefix**: fs_
- **API**:
