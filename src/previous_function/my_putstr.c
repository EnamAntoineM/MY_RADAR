/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../../lib/my.h"

int my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
    return 0;
}
