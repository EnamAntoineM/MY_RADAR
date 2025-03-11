/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** cleanup.c
*/

#include "../lib/my.h"

void cleanplane(Plane *planes, Win *winc)
{
    for (int i = 0; i < winc->p; i++){
        sfRectangleShape_destroy(planes[i].hitbox);
        sfSprite_destroy(planes[i].sprite);
        sfClock_destroy(planes[i].clock);
    }
}

void cleantower(Tower *towers, Win *winc)
{
    for (int j = 0; j < winc->t; j++){
        sfCircleShape_destroy(towers[j].circle);
    }
}

void cleanwindow(Win *winc)
{
    sfRenderWindow_destroy(winc->window);
    sfSprite_destroy(winc->sprite);
    sfTexture_destroy(winc->texture);
    sfSprite_destroy(winc->sxaffy);
    sfTexture_destroy(winc->txaffy);
    sfSprite_destroy(winc->sowaffy);
    sfTexture_destroy(winc->towaffy);
    sfClock_destroy(winc->clock);
}

void cleanup(Plane *planes, Tower *towers, Win *winc)
{
    cleanplane(planes, winc);
    cleantower(towers, winc);
    cleanwindow(winc);
}
