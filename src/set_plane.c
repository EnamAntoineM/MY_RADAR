/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** set_plane.c
*/

#include "../lib/my.h"

void hitbox(Win *winc, Plane *planes, int i)
{
    planes[i].sqsize = (sfVector2f){20, 20};
    sfRectangleShape_setSize(planes[i].hitbox, planes[i].sqsize);
    if (planes[i].immune){
        sfRectangleShape_setOutlineColor(planes[i].hitbox, sfGreen);
    } else {
        sfRectangleShape_setOutlineColor(planes[i].hitbox, sfRed);
    }
    sfRectangleShape_setOutlineThickness(planes[i].hitbox, 2.0f);
    sfRectangleShape_setFillColor(planes[i].hitbox, sfTransparent);
    sfRectangleShape_setOrigin(planes[i].hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(planes[i].hitbox, planes[i].position);
    sfRenderWindow_drawRectangleShape(winc->window, planes[i].hitbox, NULL);
}

void set_plane(Plane *planes, Win *winc)
{
    winc->txaffy = sfTexture_createFromFile("./assets/plane.png", NULL);
    if (!winc->txaffy){
        fprintf(stderr, "Failes to load the plane");
        sfTexture_destroy(winc->txaffy);
        exit(84);
    }
    for (int i = 0; i < winc->p; i++){
        if (!planes[i].sprite){
            fprintf(stderr, "Failed to create sprite for the plane");
            exit(84);
        }
        sfSprite_setTexture(planes[i].sprite, winc->txaffy, sfTrue);
        winc->plscale = (sfVector2f){0.08, 0.08};
        sfSprite_setScale(planes[i].sprite, winc->plscale);
        sfSprite_setOrigin(planes[i].sprite, (sfVector2f){142.5, 134});
    }
}
