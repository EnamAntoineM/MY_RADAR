/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** general_setting.c
*/

#include "../lib/my.h"

void remaining(Plane *planes, int i)
{
    planes[i].collided = false;
    planes[i].takeoff = false;
    planes[i].hitbox = sfRectangleShape_create();
    planes[i].clock = sfClock_create();
    planes[i].airport = false;
    planes[i].turn = angle(planes, i);
    planes[i].move = false;
    planes[i].sprite = sfSprite_create();
}

void fill_fly(char **str, Plane *planes, Win *winc)
{
    int i = 0;
    char **espace = NULL;

    for (int z = 0; str[z] != NULL; z++) {
        espace = my_str_to_word_array_space(str[z]);
        if (str[z][0] == 'A') {
            planes[i].position = (sfVector2f){atof(espace[1]),
                atof(espace[2])};
            planes[i].destination = (sfVector2f){atof(espace[3]),
                atof(espace[4])};
            planes[i].speed = atof(espace[5]);
            planes[i].vol = atof(espace[6]);
            remaining(planes, i);
            i++;
        }
    }
    set_plane(planes, winc);
}

void fill_tow(char **str, Tower *towers, Win *winc)
{
    int i = 0;
    char **espace = NULL;

    for (int z = 0; str[z] != NULL; z++) {
        espace = my_str_to_word_array_space(str[z]);
        if (str[z][0] == 'T') {
            towers[i].position = (sfVector2f){atof(espace[1]),
                atof(espace[2])};
            towers[i].radius = atof(espace[3]);
            i++;
        }
    }
    set_tower(winc);
}
