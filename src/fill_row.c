/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** fill_row.c -> cast var to the appropriate type and return a void *ptr
*/
#include "dataframe.h"
#include <stdbool.h>


static char *my_strlwr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

static void *result_bool(char *str)
{
    bool *result = malloc(sizeof(bool));

    str = my_strlwr(str);
    if (strcmp(str, "true") == 0) {
        (*result) = true;
        return result;
    }
    (*result) = false;
    return result;
}

static void *result_int(char *str)
{
    int *result = malloc(sizeof(int));

    (*result) = atoi(str);
    return result;
}

static void *result_uint(char *str)
{
    unsigned int *result = malloc(sizeof(unsigned int));

    (*result) = atol(str);
    return result;
}

static void *result_float(char *str)
{
    float *result = malloc(sizeof(float));

    (*result) = atof(str);
    return result;
}

void *fill_row(char *row, column_type_t type) //rempli chaque colonnes par l'adresse de la variable d'un data (caster dans le bon type) -> chaque colonnes doit être un void * cependant
{
    char *str = NULL;
    int num = 0;
    bool boolean = true;
    float f_num = 0.0;
    unsigned int u_num = 0;

    if (type == BOOL)
        return result_bool(row);
    if (type == INT)
        return result_int(row);
    if (type == UINT)
        return result_uint(row);
    if (type = FLOAT)
        return result_float(row);
    if (type = STRING)
        return my_strdup(row);
    return NULL;
}