/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** e
*/

#include <stdio.h>
#include <string.h>

static int check_neg(int isneg, char const *str, int *i)
{
    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            isneg = isneg * -1;
        (*i)++;
    }
    return isneg;
}

static int loop(char const *str, int i, int nb)
{
    long long int compt = nb;

    while ((str[i] >= '0') && (str[i] <= '9')) {
        compt = compt * 10 + (str[i] - '0');
        if (compt > 2147483647 || compt < -2147483648)
            return 84;
        i++;
    }
    return compt;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int isneg = 1;

    isneg = check_neg(isneg, str, &i);
    if (str[i] < '0' || str[i] > '9')
        return 0;
    nb = loop(str, i, nb);
    if (nb == 84)
        return 84;
    return nb * isneg;
}
