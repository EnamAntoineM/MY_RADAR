/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** window.h
*/

#include "../lib/my.h"
#ifndef win
    #define win
    typedef struct {
        sfRenderWindow *window;
        sfSprite *sprite;
        sfTexture *texture;
        sfSprite *sxaffy;
        sfTexture *txaffy;
        sfTexture *towaffy;
        sfSprite *sowaffy;
        sfVector2f plscale;
        sfVector2f towscale;
        sfMusic *music;
        sfClock *clock;
        bool traffic;
        double frmtime;
        int t;
        int p;
    } Win;
#endif

