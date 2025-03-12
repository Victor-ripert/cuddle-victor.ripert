/*
** EPITECH PROJECT, 2024
** flag_b.c
** File description:
** flag_b.c
*/

#include "../../include/my.h"

int flag_b(int nb)
{
    int count = 0;

    if (nb >= 2)
        count += flag_b(nb / 2);
    my_putchar((nb % 2) + '0');
    count++;
    return count;
}
