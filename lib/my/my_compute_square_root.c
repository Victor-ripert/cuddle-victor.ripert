/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** e
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int i;

    if (nb <= 0 && nb > 9)
        return 1;
    for (i = nb; i * i != nb; i--) {
        if (i <= 0)
            return 0;
    }
    return i;
}
