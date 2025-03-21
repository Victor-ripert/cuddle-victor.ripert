/*
** EPITECH PROJECT, 2025
** df_get_unique_values.c
** File description:
** e
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataframe.h"

static int is_value_equal(void *array_value, void *value, column_type_t type)
{
    if (type == STRING) {
        return strcmp((char *)array_value, (char *)value) == 0;
    } else if (memcmp(array_value, value, sizeof(*value)) == 0) {
        return 1;
    }
    return 0;
}

static int is_value_in_array(void **array, void *value, int size,
    column_type_t type)
{
    for (int i = 0; i < size; i++) {
        if (is_value_equal(array[i], value, type)) {
            return 1;
        }
    }
    return 0;
}

static void add_unique_values(unique_values_info_t *info)
{
    void *value;

    for (int i = 0; i < info->dataframe->nb_rows; i++) {
        value = df_get_value(info->dataframe, i, info->column);
        if (!is_value_in_array(info->values, value, *(info->unique_count),
            info->dataframe->column_types[info->col_index])) {
            info->values[*(info->unique_count)] = value;
            (*(info->unique_count))++;
        }
    }
    info->values[*(info->unique_count)] = NULL;
}

static int initialize_column_and_values(dataframe_t *dataframe,
    const char *column, void ***values)
{
    int col_index = -1;

    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->column_names[i], column) == 0) {
            col_index = i;
            break;
        }
    }
    if (col_index == -1)
        return -1;
    *values = malloc((dataframe->nb_rows + 1) * sizeof(void *));
    if (!*values)
        return -1;
    return col_index;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    void **values;
    int unique_count = 0;
    int col_index = 0;
    unique_values_info_t info;

    if (!dataframe)
        return NULL;
    col_index = initialize_column_and_values(dataframe, column, &values);
    if (col_index == -1)
        return NULL;
    info.dataframe = dataframe;
    info.values = values;
    info.column = column;
    info.col_index = col_index;
    info.unique_count = &unique_count;
    add_unique_values(&info);
    return values;
}
