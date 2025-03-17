/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_info.c
*/

#include "dataframe.h"

char *find_type_name(column_type_t type)
{
    type_to_str_t tab[5] = {
        {BOOL, "bool"},
        {INT, "int"},
        {UINT, "uint"},
        {FLOAT, "float"},
        {STRING, "string"},
    };

    for (int i = 0; i < 5; i++) {
        if (type == tab[i].type)
            return tab[i].name;
    }
    return "Unknow";
}

void df_info(dataframe_t *dataframe)
{
    printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        printf("- %s: %s\n", dataframe->column_names[i],
            find_type_name(dataframe->column_types[i]));
    }
}
