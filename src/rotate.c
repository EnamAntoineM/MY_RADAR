/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** rotate.c
*/

#include "../lib/my.h"

double angle(Plane *planes, int i)
{
    double cordx = planes[i].destination.x - planes[i].position.x;
    double cordy = planes[i].destination.y - planes[i].position.y;

    return atan2(cordy, cordx) * (180.0 / M_PI);
}
