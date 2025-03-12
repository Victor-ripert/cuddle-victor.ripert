/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** e
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        count++;
        nb = -nb;
    }
    if (nb >= 10) {
        count += my_put_nbr(nb / 10);
    }
    my_putchar('0' + nb % 10);
    count++;
    return count;
}
