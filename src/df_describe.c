/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe.c
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "dataframe.h"

int is_num_type(column_type_t type)
{
    return (type == INT || type == UINT || type == FLOAT);
}

static float round_to_centime(float value)
{
    return roundf(value * 100) / 100;
}

static float find_mean(dataframe_t *dataframe, int pos_column)
{
    float mean = 0;

    for (int i = 0; i < dataframe->nb_rows; i++)
        mean += atof((char *)dataframe->data[pos_column][i]);
    mean /= dataframe->nb_rows;
    return round_to_centime(mean);
}

static float find_stddev(dataframe_t *dataframe, int pos_column, float mean)
{
    float stddev = 0;
    float val = 0;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        val = atof((char *)dataframe->data[pos_column][i]);
        stddev += pow(val - mean, 2);
    }
    stddev = sqrt(stddev / dataframe->nb_rows);
    return round_to_centime(stddev);
}

static float find_max(dataframe_t *dataframe, int pos_column)
{
    float max = atof((char *)dataframe->data[pos_column][0]);
    float val = 0;

    for (int i = 1; i < dataframe->nb_rows; i++) {
        val = atof((char *)dataframe->data[pos_column][i]);
        if (val > max)
            max = val;
    }
    return round_to_centime(max);
}

static float find_min(dataframe_t *dataframe, int pos_column)
{
    float min = atof((char *)dataframe->data[pos_column][0]);
    float val = 0;

    for (int i = 1; i < dataframe->nb_rows; i++) {
        val = atof((char *)dataframe->data[pos_column][i]);
        if (val < min)
            min = val;
    }
    return round_to_centime(min);
}

void describe_loop(dataframe_t *dataframe, int pos_column)
{
    float mean = 0;
    float stddev = 0;
    float min = 0;
    float max = 0;

    if (!is_num_type(dataframe->column_types[pos_column]))
        return;
    mean = find_mean(dataframe, pos_column);
    stddev = find_stddev(dataframe, pos_column, mean);
    min = find_min(dataframe, pos_column);
    max = find_max(dataframe, pos_column);
    printf("Column: %s\n", dataframe->column_names[pos_column]);
    printf("Count: %d\n", dataframe->nb_rows);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", stddev);
    printf("Min: %.2f\n", min);
    printf("Max: %.2f\n", max);
}

void df_describe(dataframe_t *dataframe)
{
    for (int i = 0; i < dataframe->nb_columns; i++)
        describe_loop(dataframe, i);
}
