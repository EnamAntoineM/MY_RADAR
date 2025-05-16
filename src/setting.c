/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** general_setting.c
*/

#include "../lib/my.h"

void remaining(Plane *planes, int i, Win *winc)
{
    planes[i].collided = false;
    planes[i].takeoff = false;
    planes[i].hitbox = sfRectangleShape_create();
    planes[i].clock = sfClock_create();
    planes[i].airport = false;
    planes[i].turn = angle(planes, i);
    planes[i].move = false;
}

void free_me(char **conflines, char ***config, int num_planes, int num_towers, int file, char *buffer) {
    printf("Freeing memory...\n");
    for (int i = 0; i < (num_planes + num_towers); i++) {
        for (int j = 0; j < 6; j++) {
            free(config[i][j]);
        }
        free(config[i]);
    }
    free(config);
    for (int i = 0; i < (num_planes + num_towers); i++) {
        free(conflines[i]);
    }
    free(conflines);
    free(buffer);
    close(file);
    printf("Memory freed successfully.\n");
}

void fill_planes_towers(Plane *planes, Tower *towers, Win *winc, char ***config)
{
    printf("Filling planes and towers...\n");
    int k = 0;

    for (int i = 0; i < winc->p; i++) {
        printf("Filling plane %d...\n", i);
        planes[i].position.x = atof(config[i][0]);
        planes[i].position.y = atof(config[i][1]);
        planes[i].destination.x = atof(config[i][2]);
        planes[i].destination.y = atof(config[i][3]);
        planes[i].speed = atof(config[i][4]);
        planes[i].vol = atof(config[i][5]);
        remaining(planes, i, winc);
    }

    for (int i = winc->p; i < winc->p + winc->t; i++, k++) {
        printf("Filling tower %d...\n", k);
        towers[k].circle = sfCircleShape_create();
        towers[k].position.x = atof(config[i][0]);
        towers[k].position.y = atof(config[i][1]);
        towers[k].radius = atof(config[i][2]);
    }
    printf("Planes and towers filled successfully.\n");
}

void fill_buffer(char **buffer, char **argv, int file)
{
    printf("Filling buffer from file: %s\n", argv[1]);
    struct stat conf_file;
    ssize_t remaining;
    int status = stat(argv[1], &conf_file);

    if (stat(argv[1], &conf_file) == -1) {
        fprintf(stderr, "Error: Failed to stat file %s\n", argv[1]);
        close(file);
        exit(84);
    }
    *buffer = calloc((conf_file.st_size + 1), sizeof(char));
    if (file == -1) {
        fprintf(stderr, "my_radar : No such file or directory\n");
        exit(84);
    }
    remaining = read(file, *buffer, conf_file.st_size);
    if (remaining == 0) {
        fprintf(stderr, "my_radar : Empty configuration file\n");
        exit(84);
    }
    while ((remaining = read(file, *buffer, conf_file.st_size)) > 0);
    printf("Buffer content:\n%s\n", *buffer);
    printf("Buffer filled successfully.\n");
}

void fill_config(char ***config, char **conflines, int num_towers, int num_planes)
{
    printf("Filling config...\n");
    int index = 0;
    int fill = 0;
    int l = 0;

    for (int j = 0; j < (num_towers + num_planes); j++) {
        bool move = false;
        for (int i = 2; conflines[j][i] != '\0'; i++) {
            while (conflines[j][i] == ' ' || (conflines[j][i] == '\t' && conflines[j][i] != '\0')) {
                move = true;
                i++;
            }
            if (move) {
                l++;
                index = 0;
                move = false;
            }
            if (conflines[j][i] == '/') break;
            config[fill][l][index] = conflines[j][i];
            index++;
        }
        l = 0;
        index = 0;
        fill++;
    }
    printf("Config filled successfully.\n");
}

void fill_conflines(char **conflines, char *buffer)
{
    printf("Filling conflines...\n");
    int lposition = 0;
    int lindex = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        conflines[lposition][lindex] = buffer[i];
        lindex++;
        if (buffer[i] == '\n') {
            lposition++;
            lindex = 0;
        }
    }
    printf("Conflines filled successfully.\n");
}

void num_p_t(char *buffer, int *num_planes, int *num_towers, int file)
{
    for (ssize_t i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'A') {
            (*num_planes)++;
        } else if (buffer[i] == 'T') {
            (*num_towers)++;
        } else if ((buffer[i] == '\n' && buffer[i+1] != 'T') && (buffer[i] == '\n' && buffer[i+1] != 'A')) {
            if (buffer[i+1] == '\0') {} else {
                //Because that would be a character different from A and T which makes the config file invalid
                fprintf(stderr, "my_radar: Invalid config file");
                free(buffer);
                close(file);
                exit(84);
            }
        }
    }
}

void initialization_tower(Tower *towers)
{
    printf("Initializing tower...\n");
    towers->position.x = 0;
    towers->position.y = 0;
    towers->radius = 0;
    printf("Tower initialized.\n");
}

void initialization_plane(Plane *planes)
{
    printf("Initializing plane...\n");
    planes->speed = 0;
    planes->vol = 0;
    planes->position.x = 0;
    planes->position.y = 0;
    planes->destination.x = 0;
    planes->destination.y = 0;
    printf("Plane initialized.\n");
}

void char_allocation(char ***conflines, char ****config, int num_towers, int num_planes)
{
    printf("Allocating memory for conflines and config...\n");
    *config = calloc(num_planes + num_towers, sizeof(char **));
    for (int i = 0; i < (num_planes + num_towers); i++) {
        (*config)[i] = calloc(6, sizeof(char *));
        for (int j = 0; j < 6; j++) {
            (*config)[i][j] = calloc(100, sizeof(char));
        }
    }
    *conflines = calloc((num_towers + num_planes), sizeof(char *));
    for (int i = 0; i < (num_towers + num_planes); i++) {
        (*conflines)[i] = calloc(100, sizeof(char));
    }
    printf("Memory allocated successfully.\n");
}

void global_init(Plane *planes, Tower *towers, int num_planes, int num_towers)
{
    printf("Initializing global structures...\n");
    for (int i = 0; i < num_planes; i++) {
        initialization_plane(&planes[i]);
    }
    for (int j = 0; j < num_towers; j++) {
        initialization_tower(&towers[j]);
    }
    printf("Global structures initialized.\n");
}

void configuration(char **argv, Plane **planes, Tower **towers, Win *winc)
{
    printf("Starting configuration...\n");
    int file = open(argv[1], O_RDONLY);
    char *buffer = NULL;
    int k = 0;
    char **conflines = NULL;
    char ***config = NULL;

    fill_buffer(&buffer, argv, file);
    num_p_t(buffer, &winc -> p, &winc -> t, file);
    char_allocation(&conflines, &config, winc -> p, winc -> t);
    fill_conflines(conflines, buffer);
    fill_config(config, conflines, winc -> t, winc -> p);
    *planes = calloc(winc->p, sizeof(Plane));
    *towers = calloc(winc->t, sizeof(Tower));
    fill_planes_towers(*planes, *towers, winc, config);
    set_plane(*planes, winc);
    set_tower(winc);
    free_me(conflines, config, winc -> p, winc -> t, file, buffer);
    printf("Configuration completed.\n");
}