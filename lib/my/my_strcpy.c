/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** e
*/

#include <stdio.h>
#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    dest[len];
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}
