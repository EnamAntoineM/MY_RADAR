/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** flight.c
*/

#include "../lib/my.h"

sfVector2f unit_vector(sfVector2f offset)
{
    double norm_vector = sqrt((offset.x * offset.x) + (offset.y * offset.y));

    return (sfVector2f){(offset.x / norm_vector), (offset.y / norm_vector)};
}

void set(Plane *planes, double frmtime, int i)
{
    planes[i].offset =
        (sfVector2f){(planes[i].destination.x - planes[i].position.x),
            (planes[i].destination.y - planes[i].position.y)};
    planes[i].unitvec = unit_vector(planes[i].offset);
    planes[i].moveby =
        (sfVector2f){(planes[i].unitvec.x * frmtime * planes[i].speed),
            (planes[i].unitvec.y * frmtime * planes[i].speed)};
    sfSprite_move(planes[i].sprite, planes[i].moveby);
    planes[i].position =
        (sfVector2f){(planes[i].moveby.x + planes[i].position.x),
            (planes[i].moveby.y + planes[i].position.y)};
}

void turn(Plane *planes, int i)
{
    if (!planes[i].move){
        sfSprite_rotate(planes[i].sprite, planes[i].turn);
        planes[i].move = true;
    }
}

void move(Plane *planes, double frmtime, int i, Win *winc)
{
    float epsilon = 0.55f;

    sfSprite_setPosition(planes[i].sprite, planes[i].position);
    if ((fabs(planes[i].position.x - planes[i].destination.x) > epsilon) &&
    (fabs(planes[i].position.y - planes[i].destination.y) > epsilon)){
        countd(planes, winc);
        collision(planes, winc);
        if (planes[i].takeoff && !planes[i].collided){
            hitbox(winc, planes, i);
            turn(planes, i);
            sfRenderWindow_drawSprite(winc->window, planes[i].sprite, NULL);
            set(planes, frmtime, i);
        }
    } else {
        planes[i].airport = true;
    }
}

void tower(Win *winc, Tower *towers, int j)
{
    towers[j].circle = sfCircleShape_create();
    sfSprite_setPosition(winc->sowaffy, towers[j].position);
    sfRenderWindow_drawSprite(winc->window, winc->sowaffy, NULL);
    sfCircleShape_setRadius(towers[j].circle, towers[j].radius);
    sfCircleShape_setFillColor(towers[j].circle,
        sfColor_fromRGBA(255, 255, 255, 0));
    sfCircleShape_setOutlineThickness(towers[j].circle, 3.0f);
    sfCircleShape_setOutlineColor(towers[j].circle,
        sfColor_fromRGB(150, 50, 250));
    sfCircleShape_setOrigin(towers[j].circle,
        (sfVector2f){towers[j].radius, towers[j].radius});
    sfCircleShape_setPosition(towers[j].circle, towers[j].position);
}
