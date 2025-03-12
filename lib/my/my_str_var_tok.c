/*
** EPITECH PROJECT, 2024
** my_str_var_tok.c
** File description:
** e
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/my.h"

static bool check_char(char c)
{
    if ((c == '.' || c == 'o'))
        return true;
    return false;
}

static char *strncpy_select(char const *src, int day, int night)
{
    char *dest = malloc(sizeof(char) * (night - day + 1));
    int day_i = day - 1;
    int i = 0;
    int compt = 0;

    for (; i < (night - day + 1); i++)
        if (check_char(src[day_i + i])) {
            dest[compt] = src[day_i + i];
            compt++;
        }
    dest[i + 1] = '\0';
    return dest;
}

char **my_str_var_tok(char const *str, char **tab)
{
    int day = 1;
    int j = 0;
    int len = my_strlen(str) + 1;

    for (int i = 0; i < len; i++) {
        if (check_char(str[i]) == false && check_char(str[i - 1]) == true){
            tab[j] = my_strdup(strncpy_select(str, day, i));
            day = i + 2;
            j++;
        }
    }
    return tab;
}
