/*
** EPITECH PROJECT, 2024
** my_basic_call.c
** File description:
** e
*/

#include "../../include/my_printf.h"

int print_char(va_list args, const char *format)
{
    my_putchar(va_arg(args, int));
    return 1;
}

int print_nbr(va_list args, const char *format)
{
    int size = my_put_nbr(va_arg(args, int));

    return size;
}

int print_str(va_list args, const char *format)
{
    int size = my_putstr(va_arg(args, char *));

    return size;
}

int print_pourcent(va_list args, const char *format)
{
    my_putchar('%');
    return 1;
}

int print_float(va_list args, const char *format)
{
    int precision = 6;
    int value = 0;
    int compt = 0;
    int size = my_put_float(va_arg(args, double), precision, value, compt);

    return size;
}
