/*
** EPITECH PROJECT, 2024
** octal.c
** File description:
** octal.c
*/

#include "../../include/my_printf.h"

int oct(int nb)
{
    int count = 0;

    if (nb >= 8)
        count += oct(nb / 8);
    my_putchar((nb % 8) + '0');
    count++;
    return count;
}
