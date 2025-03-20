/*
** EPITECH PROJECT, 2025
** df_filter.c
** File description:
** e
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataframe.h"

static void copy_filtered_row(filter_context_t *ctx, int i)
{
    if (!ctx->filter_func(ctx->df->data[ctx->col_index][i]))
        return;
    for (int j = 0; j < ctx->df->nb_columns; j++)
        ctx->new_df->data[j][*(ctx->new_i)] =
            strdup((char *)ctx->df->data[j][i]);
    (*(ctx->new_i))++;
}

static dataframe_t *create_dataframe(int nb_columns, int nb_rows,
    dataframe_t *origine)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));

    df->nb_columns = nb_columns;
    df->nb_rows = nb_rows;
    df->column_names = malloc(sizeof(char *) * nb_columns);
    df->column_types = malloc(sizeof(column_type_t) * nb_columns);
    df->data = malloc(sizeof(void *) * nb_columns);
    df->separator = strdup(origine->separator);
    if (!df->column_names || !df->column_types || !df->data) {
        free(df->column_names);
        free(df->column_types);
        free(df->data);
        free(df);
        return NULL;
    }
    for (int i = 0; i < nb_columns; i++) {
        df->column_names[i] = origine->column_names[i];
        df->data[i] = malloc(sizeof(void *) * nb_rows);
    }
    return df;
}

dataframe_t *df_filter(dataframe_t *df, const char *column,
    bool (*filter_func)(void *))
{
    int col_index = -1;
    int new_i = 0;
    dataframe_t *new_df = create_dataframe(df->nb_columns, df->nb_rows, df);
    filter_context_t ctx;

    for (int i = 0; i < df->nb_columns && col_index == -1; i++)
        if (!strcmp(df->column_names[i], column))
            col_index = i;
    if (col_index == -1)
        return NULL;
    ctx.df = df;
    ctx.new_df = new_df;
    ctx.col_index = col_index;
    ctx.new_i = &new_i;
    ctx.filter_func = filter_func;
    for (int i = 0; i < df->nb_rows; i++)
        copy_filtered_row(&ctx, i);
    new_df->nb_rows = new_i;
    return new_df;
}
