/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** e
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int count = 0;

    if (nb <= 0)
        return 0;
    for (int i = 1; i <= nb; i++) {
        if (nb % i == 0)
            count++;
    }
    if (count != 2)
        return 0;
    else
        return 1;
}
