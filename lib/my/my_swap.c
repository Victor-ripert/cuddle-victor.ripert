/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** e
*/

#include <stdio.h>
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int c;

    c = *b;
    *b = *a;
    *a = c;
}
