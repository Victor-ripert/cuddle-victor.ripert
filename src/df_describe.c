/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe.c
*/
#include "dataframe.h"
#include <math.h>

int is_num_type(column_type_t type) {
    if (type == INT)
        return 0;
    if (type == UINT)
        return 0;
    if (type == FLOAT)
        return 0;
    return 84;
}

static float find_mean(dataframe_t *dataframe, int pos_column)
{
    float mean = 0;
    float *tmp = NULL;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = (float *)dataframe->data[i][pos_column];
        mean += (*tmp);
    }
    mean = mean / dataframe->nb_rows;
    return mean;
}

static float find_stddev(dataframe_t *dataframe, int pos_column, float mean)
{
    float stddev = 0;
    float *tmp = NULL;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = (float *)dataframe->data[i][pos_column];
        stddev += pow(((*tmp) - mean), 2);
    }
    stddev /= dataframe->nb_rows;
    stddev = sqrt(stddev);
    return stddev;
}

static float find_max(dataframe_t *dataframe, int pos_column)
{
    float *tmp = (float *)dataframe->data[pos_column][0];
    float max = tmp[0];
    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = (float *)dataframe->data[pos_column][i];
        if (tmp[0] > max)
            max = tmp[0];
    }
    return max;
}

static float find_min(dataframe_t *dataframe, int pos_column)
{
    float *tmp = (float *)dataframe->data[1][pos_column];
    float min = (*tmp);

    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = (float *)dataframe->data[pos_column][i];
        if ((*tmp) < min)
            min = (*tmp);
    }
    return min;
}

int describe_loop(dataframe_t *dataframe, int pos_column)
{
    float mean = 0;
    float stddev = 0;
    float min = 0;
    float max = 0;

    if (is_num_type(dataframe->column_types[pos_column])!= 0)
        return 84;
    mean = find_mean(dataframe, pos_column);
    stddev = find_stddev(dataframe, pos_column, mean);
    min = find_min(dataframe, pos_column);
    max = find_max(dataframe, pos_column);
    printf("Name: %s\n", dataframe->column_names[pos_column]);
    printf("Count: %d\n", dataframe->nb_rows);
    printf("Mean: %f\n", mean);
    printf("Std: %f\n", stddev);
    printf("Min: %f\n", min);
    printf("Max: %f\n", max);
}

void df_describe(dataframe_t *dataframe)
{
    for (int i = 0; i < dataframe->nb_columns; i++) {
        describe_loop(dataframe, i);
    }
    return 0;
}