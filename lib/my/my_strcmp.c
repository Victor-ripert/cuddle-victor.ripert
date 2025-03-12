/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** e
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (unsigned char)(*s1) - (unsigned char)(*s2);
        }
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}
