/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_shape.c
*/

#include "dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t dataframe_shape;

    dataframe_shape.nb_columns = dataframe->nb_columns;
    dataframe_shape.nb_rows = dataframe->nb_rows;
    return dataframe_shape;
}