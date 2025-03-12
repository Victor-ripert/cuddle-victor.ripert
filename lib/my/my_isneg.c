/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** e
*/

#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
