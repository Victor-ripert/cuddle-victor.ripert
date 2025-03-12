/*
** EPITECH PROJECT, 2024
** my_printf.h
** File description:
** e
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #define MAX_SIZE 1000

typedef struct c_flags_s {
    char flag;
    int (*ptr_func)(va_list, const char *);
} c_flags_t;


void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcpy(char *dest, char const *src);
int my_showstr(char const *str);
int flag_n(int *nb, const char *format);
int print_char(va_list args, const char *format);
int print_nbr(va_list args, const char *format);
int print_str(va_list args, const char *format);
int print_pourcent(va_list args, const char *format);
int print_float(va_list args, const char *format);
int print_o(va_list args, const char *format);
int print_x(va_list args, const char *format);
int print_u(va_list args, const char *format);
int print_n(va_list args, const char *format);
int print_b(va_list args, const char *format);
int flag_n(int *nb, const char *format);
int flag_u(int nb);
int flag_b(int nb);
int oct(int nb);
int hex(int nb);
int my_printf(const char *format, ...);
int my_put_float(double float_value, int precision, int value, int compt);

    #define SIZE_BUFF 32000

#endif /* MY_H_ */
