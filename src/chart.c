/*
** EPITECH PROJECT, 2024
** B-MUL-100-COT-1-1-myradar
** File description:
** chart.c
*/

#include "../lib/my.h"

char **chart(char **argv)
{
    struct stat st;
    char **str;
    char *buffer;
    int red;
    int file = open(argv[1], O_RDONLY);

    if (file == -1){
        fprintf(stderr, "my_radar : No such file or directory");
        exit(84);
    }
    stat(argv[1], &st);
    buffer = malloc(sizeof(char) * st.st_size);
    red = read(file, buffer, st.st_size);
    if (red == 0){
        fprintf(stderr, "my_radar : Empty configuration file");
        exit(84);
    }
    str = my_str_to_word_array(buffer);
    free(buffer);
    return str;
}
