/*
** EPITECH PROJECT, 2024
** my_strcasecmp.c
** File description:
** e
*/

int my_strcasecmp(const char *s1, const char *s2)
{
    char c1 = *s1;
    char c2 = *s2;

    while (*s1 != '\0' && *s2 != '\0') {
        c1 = *s1;
        c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 'a' - 'A';
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 'a' - 'A';
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
