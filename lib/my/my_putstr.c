/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** e
*/

#include <stddef.h>
#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return my_strlen(str) - 1;
}
