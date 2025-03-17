/*
** EPITECH PROJECT, 2025
** check_type.c
** File description:
** Functions to detect and parse data types
*/

#include "dataframe.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int is_int(const char *str)
{
    int i = (str[0] == '-') ? 1 : 0;

    for (; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return 0;
    return (i > 0);
}

static int is_uint(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return 0;
    return (str[0] != '\0');
}

static int is_valid_float_char(char c, int *dot_count)
{
    if (c == '.') {
        ++(*dot_count);
        if ((*dot_count) > 1)
            return 0;
    } else if (!isdigit(c))
        return 0;
    return 1;
}

static int is_float(const char *str)
{
    int dot_count = 0;
    int i = (str[0] == '-') ? 1 : 0;

    for (; str[i] != '\0'; i++) {
        if (!is_valid_float_char(str[i], &dot_count))
            return 0;
    }
    return (i > 0 && dot_count == 1);
}

static int is_bool(const char *str)
{
    return (!strcmp(str, "true") || !strcmp(str, "false"));
}

column_type_t detect_type(const char *str)
{
    if (is_bool(str))
        return BOOL;
    if (is_int(str))
        return INT;
    if (is_uint(str))
        return UINT;
    if (is_float(str))
        return FLOAT;
    return STRING;
}

column_type_t detect_column_type(dataframe_t *dataframe, int col)
{
    column_type_t type = detect_type((char *)dataframe->data[col][0]);
    column_type_t current_type = STRING;

    for (int i = 1; i < dataframe->nb_rows; i++) {
        current_type = detect_type((char *)dataframe->data[col][i]);
        if (current_type == STRING)
            return STRING;
        if ((current_type == FLOAT && type == INT) ||
            (current_type == FLOAT && type == UINT))
            type = FLOAT;
        if (current_type == INT && type == UINT)
            type = INT;
    }
    return type;
}
