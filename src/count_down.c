/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** count_down.c
*/

#include "../lib/my.h"

void cond(Plane *planes, int i)
{
    float seconds = 0;
    sfTime elapsed;

    if (planes[i].vol > 0) {
        elapsed =
            sfClock_getElapsedTime(planes[i].clock);
        seconds =
            sfTime_asSeconds(elapsed);
        if (seconds >= 1.0f) {
            planes[i].vol--;
            sfClock_restart(planes[i].clock);
        }
    }
}

void countd(Plane *planes, Win *winc)
{
    for (int i = 0; i < winc->p; i++) {
        cond(planes, i);
        if (planes[i].vol <= 0){
            planes[i].takeoff = true;
        }
    }
}
