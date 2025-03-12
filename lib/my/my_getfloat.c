/*
** EPITECH PROJECT, 2024
** my_getfloat.c
** File description:
** e
*/

#include <stdio.h>

static float parse_integer(const char **str)
{
    float result = 0.0;

    while (**str >= '0' && **str <= '9') {
        result = result * 10 + (**str - '0');
        (*str)++;
    }
    return result;
}

static float parse_decimal(const char **str)
{
    float decimal_part = 0.0;
    int decimal_place = 1;

    if (**str == '.') {
        (*str)++;
        while (**str >= '0' && **str <= '9') {
            decimal_part = decimal_part * 10 + (**str - '0');
            decimal_place *= 10;
            (*str)++;
        }
    }
    return decimal_part / decimal_place;
}

float my_getfloat(const char *str)
{
    float result = 0.0;
    float decimal_part = 0.0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    result = parse_integer(&str);
    decimal_part = parse_decimal(&str);
    return (result + decimal_part) * sign;
}
