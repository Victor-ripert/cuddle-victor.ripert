/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** e
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *copy = malloc(sizeof(char) * my_strlen(src) + 1);

    copy = my_strcpy(copy, src);
    copy[my_strlen(copy)] = '\0';
    return copy;
}
