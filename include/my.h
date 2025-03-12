/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** e
*/

#ifndef MY_H_
    #define MY_H_
    #include <stddef.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int flag_n(int *nb, const char *format);
char **my_str_to_word_array(char const *str, char separator);
char **my_str_var_tok(char const *str, char **tab);
char *my_strdup(char const *src);
int my_printf(const char *format, ...);
int my_strcasecmp(const char *s1, const char *s2);
float my_getfloat(const char *str);

    #define SIZE_BUFF 32000

#endif /* MY_H_ */
