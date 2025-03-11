/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int s = 1;

    if (str[0] == '-') {
        s = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            n = (n * 10) + (str[i] - '0');
        } else {
            break;
        }
    }
    return n * s;
}
