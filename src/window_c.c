/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** window_c.c
*/

#include "../lib/my.h"

void display(Win *winc, Plane *planes, Tower *towers)
{
    immunity(planes, towers, winc);
    sfRenderWindow_clear(winc->window, sfBlack);
    sfRenderWindow_drawSprite(winc->window, winc->sprite, NULL);
    winc->frmtime = sfTime_asSeconds(sfClock_restart(winc->clock));
    for (int j = 0; j < winc->t; j++){
        tower(winc, towers, j);
        sfRenderWindow_drawCircleShape(winc->window, towers[j].circle, NULL);
    }
    for (int i = 0; i < winc->p; i++){
        move(planes, winc->frmtime, i, winc);
    }
    sfRenderWindow_display(winc->window);
}

void runtime(Plane *fly, Tower *towers, sfEvent event, Win *winc)
{
    while (sfRenderWindow_pollEvent(winc->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(winc->window);
    }
    display(winc, fly, towers);
}

void c_map(Win *winc)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfVector2f scale = {0.499, 0.465};

    winc->window = sfRenderWindow_create(mode, "My radar",
        sfResize | sfClose, NULL);
    if (!winc->window)
        exit(84);
    sfRenderWindow_setFramerateLimit(winc->window, 60);
    winc->texture =
        sfTexture_createFromFile("./assets/my_radar_map.png", NULL);
    if (!winc->texture){
        fprintf(stderr, "Failed to load the map");
        exit(84);
    }
    winc->sprite = sfSprite_create();
    sfSprite_setTexture(winc->sprite, winc->texture, sfTrue);
    sfSprite_setScale(winc->sprite, scale);
    winc->clock = sfClock_create();
}

void window(char **argv)
{
    sfEvent event;
    Win winc = {0};
    Plane *fly;
    Tower *towers;
    char **str = chart(argv);

    winc.p = num_p(str);
    winc.t = num_t(str);
    fly = malloc(sizeof(Plane) * winc.p);
    towers = malloc(sizeof(Tower) * winc.t);
    fill_fly(str, fly, &winc);
    fill_tow(str, towers, &winc);
    c_map(&winc);
    while (sfRenderWindow_isOpen(winc.window)) {
        runtime(fly, towers, event, &winc);
    }
    cleanup(fly, towers, &winc);
    free(fly);
    free(towers);
}
