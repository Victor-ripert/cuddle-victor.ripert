/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** my_printf implementation
*/

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "../../include/my_printf.h"

const c_flags_t list[] = {
    {'b', print_b},
    {'n', print_n},
    {'c', print_char},
    {'i', print_nbr},
    {'d', print_nbr},
    {'s', print_str},
    {'f', print_float},
    {'F', print_float},
    {'o', print_o},
    {'x', print_x},
    {'u', print_u},
    {'%', print_pourcent},
    {'\0', NULL}
};

int check(va_list params, const char *format, int i)
{
    for (int j = 0; list[j].flag != '\0'; j++) {
        if (list[j].flag == format[i]) {
            return list[j].ptr_func(params, format);
        }
    }
    return 84;
}

int my_printf(const char *format, ...)
{
    va_list params;
    int size = 0;

    va_start(params, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            size++;
            continue;
        }
        i++;
        size += check(params, format, i);
        if (size == 84) {
            va_end(params);
            return 84;
        }
    }
    va_end(params);
    return size;
}
