/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** e
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/my.h"

static bool check_char(char c, char separator)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') || (c == '.'))
        return true;
    return false;
}

static char *strncpy_select(char const *src, int day, int night,
    char separator)
{
    char *dest = malloc(sizeof(char) * (night - day + 1));
    int day_i = day - 1;
    int i = 0;
    int compt = 0;

    for (; i < (night - day + 1); i++)
        if (check_char(src[day_i + i], separator)) {
            dest[compt] = src[day_i + i];
            compt++;
        }
    dest[i + 1] = '\0';
    return dest;
}

char **my_str_to_word_array(char const *str, char separator)
{
    char **tab = malloc(sizeof(char *) * my_strlen(str));
    int day = 1;
    int j = 0;
    int len = my_strlen(str) + 1;

    for (int i = 0; i < len; i++) {
        if (check_char(str[i], separator) == false && check_char(str[i - 1],
            separator) == true){
            tab[j] = my_strdup(strncpy_select(str, day, i, separator));
            day = i + 2;
            j++;
        }
    }
    return tab;
}
