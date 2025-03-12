/*
** EPITECH PROJECT, 2024
** hex.c
** File description:
** hex.c
*/

#include "../../include/my.h"

int hex(int nb)
{
    int count = 0;

    if (nb >= 16) {
        count += hex(nb / 16);
    }
    if (nb % 16 < 10) {
        my_putchar((nb % 16) + '0');
    } else {
        my_putchar((nb % 16) - 10 + 'a');
    }
    count++;
    return count;
}
