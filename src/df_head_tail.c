/*
** EPITECH PROJECT, 2025
** df_head
** File description:
** e
*/

#include "dataframe.h"
#include <stdlib.h>
#include <string.h>

static void copy_column_data(dataframe_t *new_df, dataframe_t *dataframe,
    int start_row, int nb_rows)
{
    for (int j = 0; j < dataframe->nb_columns; j++) {
        new_df->data[j] = malloc(sizeof(void *) * nb_rows);
        for (int i = 0; i < nb_rows; i++)
            new_df->data[j][i] =
            strdup((char *)dataframe->data[j][start_row + i]);
    }
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));

    if (nb_rows > dataframe->nb_rows)
        nb_rows = dataframe->nb_rows;
    new_df->separator = strdup(dataframe->separator);
    new_df->nb_rows = nb_rows;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->column_names = malloc(sizeof(char *) * dataframe->nb_columns);
    new_df->column_types = malloc(sizeof(column_type_t) *
        dataframe->nb_columns);
    new_df->data = malloc(sizeof(void *) * dataframe->nb_columns);
    if (!new_df->column_names || !new_df->column_types || !new_df->data)
        return NULL;
    for (int j = 0; j < dataframe->nb_columns; j++) {
        new_df->column_names[j] = strdup(dataframe->column_names[j]);
        new_df->column_types[j] = dataframe->column_types[j];
    }
    copy_column_data(new_df, dataframe, 0, nb_rows);
    return new_df;
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));
    int start_row;

    if (nb_rows > dataframe->nb_rows)
        nb_rows = dataframe->nb_rows;
    start_row = dataframe->nb_rows - nb_rows;
    new_df->nb_rows = nb_rows;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->column_names = malloc(sizeof(char *) * dataframe->nb_columns);
    new_df->column_types = malloc(sizeof(column_type_t) *
        dataframe->nb_columns);
    new_df->data = malloc(sizeof(void *) * dataframe->nb_columns);
    if (!new_df->column_names || !new_df->column_types || !new_df->data)
        return NULL;
    for (int j = 0; j < dataframe->nb_columns; j++) {
        new_df->column_names[j] = strdup(dataframe->column_names[j]);
        new_df->column_types[j] = dataframe->column_types[j];
    }
    copy_column_data(new_df, dataframe, start_row, nb_rows);
    return new_df;
}
