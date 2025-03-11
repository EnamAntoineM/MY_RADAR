/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1
** File description: number of arguments and help info
** arg_check1.c
*/

#include "../lib/my.h"

void check1(int ac)
{
    if (ac < 2){
        message(1);
    }
    else if (ac > 2){
        message(2);
    }
}
