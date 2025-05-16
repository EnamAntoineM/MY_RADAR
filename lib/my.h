/*
** EPITECH PROJECT, 2024
** AFFYKKE.MY_RADAR
** File description: Prototypes
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include "c_lib.h"
    #include "sfml.h"
    #include "../structures/window.h"
    #include "../structures/plane.h"
    #include "../structures/tower.h"
    double angle (Plane *planes, int i);
    float cdistance(sfVector2f point1, sfVector2f point2);
    void immunity(Plane *planes, Tower *towers, Win *winc);
    void countd(Plane *planes, Win *winc);
    void collision(Plane *planes, Win *winc);
    void tower(Win *winc, Tower *towers, int j);
    void cleanup(Plane *planes, Tower *towers, Win *winc);
    void hitbox(Win *winc, Plane *planes, int i);
    sfVector2f unit_vector(sfVector2f offset);
    void move(Plane *planes, double frmtime, int i, Win *winc);
    void set_tower(Win *winc);
    void set_plane(Plane *planes, Win *winc);
    void configuration(char **argv, Plane **planes, Tower **towers, Win *winc);
    void my_usage(int argc, char **argv);
    void message(int type);
    void check1(int ac);
    void window(char **argv);
#endif
