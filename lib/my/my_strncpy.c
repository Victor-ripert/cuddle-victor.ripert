/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** e
*/

#include <stdio.h>

static int my_slen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_slen(src);

    dest[len];
    for (int i = 0; i <= n - 1; i++)
        dest[i] = src[i];
    return dest;
}
