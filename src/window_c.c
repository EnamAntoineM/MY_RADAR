/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** window_c.c
*/

#include "../lib/my.h"

void display(Win *winc, Plane *planes, Tower *towers) {
  immunity(planes, towers, winc);
  sfRenderWindow_clear(winc->window, sfBlack);
  sfRenderWindow_drawSprite(winc->window, winc->sprite, NULL);
  winc->frmtime = sfTime_asSeconds(sfClock_restart(winc->clock));

  for (int j = 0; j < winc->t; j++) {
    tower(winc, towers, j);
    sfRenderWindow_drawCircleShape(winc->window, towers[j].circle, NULL);
  }

  for (int i = 0; i < winc->p; i++) {
    move(planes, winc->frmtime, i, winc);
  }

  sfRenderWindow_display(winc->window);
}

void runtime(Plane *fly, Tower *towers, sfEvent event, Win *winc) {
  while (sfRenderWindow_pollEvent(winc->window, &event)) {
    if (event.type == sfEvtClosed) {
      sfRenderWindow_close(winc->window);
    }
  }
  display(winc, fly, towers);
}

void c_map(Win *winc) {
  printf("Initializing video mode...\n");
  sfVideoMode mode = {1920, 1080, 64};
  sfVector2f scale = {1, 1};
  printf("Creating render window...\n");
  winc->window = sfRenderWindow_create(mode, "My radar", sfResize | sfClose,
                                       sfWindowed, NULL);
  if (!winc->window) {
    printf("Failed to create render window. Exiting...\n");
    exit(84);
  }
  printf("Setting framerate limit...\n");
  sfRenderWindow_setFramerateLimit(winc->window, 60);

  printf("Loading texture from file...\n");
  winc->texture = sfTexture_createFromFile("./assets/my_radar_map.png", NULL);
  if (!winc->texture) {
    fprintf(stderr, "Failed to load the map\n");
    exit(84);
  }
  printf("Creating sprite and setting texture...\n");
  winc->sprite = sfSprite_create(winc->texture);
  sfSprite_setTexture(winc->sprite, winc->texture, true);
  sfSprite_setScale(winc->sprite, scale);

  printf("Creating clock...\n");
  winc->clock = sfClock_create();
  printf("c_map function completed successfully.\n");
}

void window(char **argv) {
  sfEvent event;
  Win *winc = calloc(1, sizeof(Win));
  Plane *fly;
  Tower *towers;

  configuration(argv, &fly, &towers, winc);
  c_map(winc);
  while (sfRenderWindow_isOpen(winc->window)) {
    runtime(fly, towers, event, winc);
  }
  cleanup(fly, towers, winc);
  free(fly);
  free(towers);
  free(winc);
}
