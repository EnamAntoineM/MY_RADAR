/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** error_msg.c
*/

#include "../lib/my.h"

void message2(int type)
{
    if (type == 2){
        fprintf(stderr, "Too many arguments\n"
            "Type ./my_radar -h for more information");
    } else if (type == 3){
        fprintf(stderr, "Invalid argument\n");
    }
}

void message(int type)
{
    if (type == 1){
        fprintf(stderr, "Not enough arguments !\n"
            "Type ./my_radar -h for more information");
    }
    message2(type);
    exit(84);
}
