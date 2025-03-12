/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** e
*/

#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    while (*dest)
        ++dest;
    while (*src) {
        *dest = *src;
        *dest++;
        *src++;
    }
    *dest = '\0';
    return dest;
}
