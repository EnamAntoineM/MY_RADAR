/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** num_tower.c
*/

#include "../lib/my.h"

int num_t(char **str)
{
    int a = 0;

    for (int z = 0; str[z] != NULL; z++) {
        if (str[z][0] == 'T') {
            a++;
        }
    }
    return a;
}
