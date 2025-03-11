/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** plane.h
*/

#include "../lib/my.h"
#ifndef plane
    #define plane
    typedef struct {
        sfVector2f scale;
        sfSprite *sprite;
        sfVector2f position;
        sfVector2f destination;
        sfVector2f offset;
        sfVector2f moveby;
        sfVector2f unitvec;
        sfRectangleShape *hitbox;
        sfVector2f sqsize;
        sfClock *clock;
        double turn;
        bool move;
        bool immune;
        bool collided;
        bool takeoff;
        bool airport;
        double rotation;
        double speed;
        double vol;
    } Plane;
#endif

