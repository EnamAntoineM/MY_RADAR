/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "../../lib/my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *p = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    * dest = '\0';
    return p;
}
