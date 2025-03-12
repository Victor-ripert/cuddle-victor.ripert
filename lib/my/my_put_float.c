/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** e
*/

#include "../../include/my.h"

static int display_float(int compt, char *buffer)
{
    int value = compt - 1;

    while (compt) {
        compt--;
        my_putchar(buffer[compt]);
    }
    return value;
}

int my_put_float(double float_value, int precision, int value, int compt)
{
    char buffer[32];

    if ((int)float_value == 0) {
        my_putchar('0');
    }
    for (compt = 0; compt < precision; compt++)
        float_value *= 10.0;
    float_value += 0.5;
    value = (float_value);
    compt = 0;
    while (value) {
        buffer[compt] = ((value % 10) + '0');
        compt++;
        value = value / 10;
        if (compt == precision) {
            buffer[compt] = '.';
            compt++;
        }
    }
    return display_float(compt, buffer);
}
