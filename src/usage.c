/*
** EPITECH PROJECT, 2024
** usage.c
** File description:
** usage.c
*/

#include "../lib/my.h"

void my_usage(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            printf("Air traffic simulation panel\n");
            printf("USAGE\n");
            printf(" ./my_radar [OPTIONS] path_to_script\n");
            printf("  path_to_script     The path to the script file.\n");
            printf("OPTIONS\n");
            printf(" -h                print the usage and quit.\n");
            printf("USER INTERACTIONS\n");
            printf(" 'L' key        enable/disable hitboxes and areas.\n");
            printf(" 'S' key        enable/disable sprites.\n");
            exit(0);
        }
    }
}
