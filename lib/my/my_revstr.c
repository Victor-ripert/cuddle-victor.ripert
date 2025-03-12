/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"

char *my_revstr(char *str)
{
    char temp;
    int len = my_strlen(str) - 1;

    for (int i = 0; i <= len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return str;
}
