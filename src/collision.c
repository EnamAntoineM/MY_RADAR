/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** collision.c
*/

#include "../lib/my.h"

int cond4(Plane *planes, int distance, int i, int j)
{
    if (distance <= 25) {
        planes[i].collided = true;
        planes[j].collided = true;
        planes[i].airport = true;
        planes[j].airport = true;
    }
    return 0;
}

float cdistance(sfVector2f point1, sfVector2f point2)
{
    float dx = point1.x - point2.x;
    float dy = point1.y - point2.y;

    return sqrt(dx * dx + dy * dy);
}

void cond2(Plane *planes, int i, int j)
{
    float distance = 0;

    if (i != j && planes[i].takeoff && planes[j].takeoff) {
        if (!planes[i].airport && !planes[j].airport &&
            !planes[i].immune &&
            !planes[j].immune) {
            distance = cdistance(planes[i].position, planes[j].position);
            cond4(planes, distance, i, j);
        }
    }
}

void cond1(Plane *planes, Win *winc, int i)
{
    if (!planes[i].collided) {
        for (int j = 0; j < winc->p; j++) {
            cond2(planes, i, j);
        }
    }
}

void collision(Plane *planes, Win *winc)
{
    for (int i = 0; i < winc->p; i++) {
        cond1(planes, winc, i);
    }
}
