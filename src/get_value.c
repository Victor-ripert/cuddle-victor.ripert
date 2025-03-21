/*
** EPITECH PROJECT, 2025
** get_value.c
** File description:
** e
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataframe.h"

static int *get_int_value(char *data)
{
    int *int_value = malloc(sizeof(int));

    if (!int_value)
        return NULL;
    *int_value = atoi(data);
    return int_value;
}

static unsigned int *get_uint_value(char *data)
{
    unsigned int *uint_value = malloc(sizeof(unsigned int));

    if (!uint_value)
        return NULL;
    *uint_value = (unsigned int)strtoul(data, NULL, 10);
    return uint_value;
}

static float *get_float_value(char *data)
{
    float *float_value = malloc(sizeof(float));

    if (!float_value)
        return NULL;
    *float_value = atof(data);
    return float_value;
}

static int *get_bool_value(char *data)
{
    int *bool_value = malloc(sizeof(int));

    if (!bool_value)
        return NULL;
    *bool_value = (strcmp(data, "1") == 0) ? 1 : 0;
    return bool_value;
}

static void *get_typed_value(dataframe_t *dataframe, int col_index, int row)
{
    char *data = (char *)dataframe->data[col_index][row];
    column_type_t type = dataframe->column_types[col_index];

    if (type == INT)
        return get_int_value(data);
    if (type == UINT)
        return get_uint_value(data);
    if (type == FLOAT)
        return get_float_value(data);
    if (type == STRING)
        return data;
    if (type == BOOL)
        return get_bool_value(data);
    return NULL;
}

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int col_index = -1;

    if (!dataframe || row < 0 || row >= dataframe->nb_rows)
        return NULL;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->column_names[i], column) == 0) {
            col_index = i;
            break;
        }
    }
    if (col_index == -1)
        return NULL;
    return get_typed_value(dataframe, col_index, row);
}
