/*
** EPITECH PROJECT, 2024
** flag_n.c
** File description:
** flag_n.c
*/

#include <stdio.h>

int flag_n(int *nb, const char *format)
{
    int i = 0;

    for (; format[i] != '%'; i++);
    *nb = i;
    return *nb;
}
