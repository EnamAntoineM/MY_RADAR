/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include "../../lib/my.h"
char *my_strncpy(char *dest, char const *src, int n)
{
    char *p = dest;
    int i;

    for (i = 0; i < n; i++) {
        *dest = *src;
        dest++;
        src++;
    }
    if (n > src)
        * dest = '\0';
    return p;
}
