/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** tower.h
*/

#include "../lib/my.h"
#ifndef tower
    #define win
    typedef struct {
        sfVector2f scale;
        sfVector2f position;
        sfCircleShape *circle;
        double radius;
    } Tower;
#endif

