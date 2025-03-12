/*
** EPITECH PROJECT, 2024
** my_flags_nbr.c
** File description:
** e
*/

#include "../../include/my_printf.h"

int print_o(va_list args, const char *format)
{
    int size = oct(va_arg(args, int));

    return size;
}

int print_x(va_list args, const char *format)
{
    int size = hex(va_arg(args, int));

    return size;
}

int print_u(va_list args, const char *format)
{
    int size = flag_u(va_arg(args, int));

    return size;
}

int print_n(va_list args, const char *format)
{
    flag_n(va_arg(args, int *), format);
}

int print_b(va_list args, const char *format)
{
    int size = flag_b(va_arg(args, int));

    return size;
}
