/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** set_tower.c
*/


#include "../lib/my.h"

void set_tower(Win *winc)
{
    winc->towaffy = sfTexture_createFromFile("./assets/tower.png", NULL);
    if (!winc->towaffy){
        fprintf(stderr, "Failes to load the tower");
        sfTexture_destroy(winc->towaffy);
        exit(84);
    }
    winc->sowaffy = sfSprite_create();
    if (!winc->sowaffy){
        fprintf(stderr, "Failed to create sprite for the tower");
        exit(84);
    }
    sfSprite_setTexture(winc->sowaffy, winc->towaffy, sfTrue);
    winc->towscale = (sfVector2f){0.1, 0.1};
    sfSprite_setScale(winc->sowaffy, winc->towscale);
    sfSprite_setOrigin(winc->sowaffy, (sfVector2f){250, 250});
}
