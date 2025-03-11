/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** indestructible.c
*/

#include "../lib/my.h"

void step(Plane *planes, Tower *towers, Win *winc, int i)
{
    float youyou = 0;

    for (int j = 0; j < winc->t; j++){
        youyou = cdistance(planes[i].position,
            towers[j].position);
        if (youyou <= (towers[j].radius + 15)){
            planes[i].immune = true;
            break;
        } else {
            planes[i].immune = false;
        }
    }
}

void immunity(Plane *planes, Tower *towers, Win *winc)
{
    for (int i = 0; i < winc->p; i++){
        step(planes, towers, winc, i);
    }
}
