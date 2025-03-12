/*
** EPITECH PROJECT, 2024
** flag_u
** File description:
** flag_u.c
*/

#include "../../include/my.h"

int flag_u(unsigned int nb)
{
    int count = 0;

    if (nb >= 10) {
        count += flag_u(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    count++;
    return count;
}
