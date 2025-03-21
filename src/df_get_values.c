/*
** EPITECH PROJECT, 2025
** df_get_values.c
** File description:
** e
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataframe.h"

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    void **values;
    int col_index = -1;

    if (!dataframe || !column || dataframe->nb_rows == 0)
        return NULL;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->column_names[i], column) == 0) {
            col_index = i;
            break;
        }
    }
    if (col_index == -1)
        return NULL;
    values = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (!values)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++)
        values[i] = df_get_value(dataframe, i, column);
    values[dataframe->nb_rows] = NULL;
    return values;
}
