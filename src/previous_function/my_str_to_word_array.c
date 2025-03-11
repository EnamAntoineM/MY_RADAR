/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../../lib/my.h"

int numbers_words_prenium(char const *str, variable_t d)
{
    while ((str[d.i] != '\n') && (str[d.i] != '\0')) {
        d.i++;
    }
    return d.i;
}

int func_i(char const *str, variable_t d)
{
    if (str[d.i] == '\n') {
        d.i++;
    }
    return d.i;
}

int numbers_words(char const *str, variable_t d)
{
    int j = 0;

    d.i = 0;
    while (str[d.i] != '\0') {
                if (str[d.i] != '\n' && str[d.i] != '\0') {
            j++;
            d.i = numbers_words_prenium(str, d);
            }
        if (str[d.i] == '\n') {
            d.i++;
        }
    }
    return j;
}

char **my_str_to_word_array_prenium(char const *str, variable_t d)
{
    char **chart;
    int j = numbers_words(str, d);

    chart = malloc(sizeof(char *) * (j + 1));
    while (str[d.i] != '\0') {
        d.i = func_i(str, d);
        if (str[d.i] != '\n' && str[d.i] != '\0') {
            d.a = d.i;
            d.i = numbers_words_prenium(str, d);
            chart[d.t] = malloc(sizeof(char) * (d.i - d.a + 1));
            if (chart[d.t] != NULL)
                my_strncpy(chart[d.t], &str[d.a], d.i - d.a);
            chart[d.t][d.i - d.a] = '\0';
            d.t++;
        }
    }
    chart[d.t] = NULL;
    return chart;
}

char **my_str_to_word_array(char const *str)
{
    variable_t d;
    char **chart;

    d.i = 0;
    d.t = 0;
    d.a = 0;
    d.b = 0;
    chart = my_str_to_word_array_prenium(str, d);
    return chart;
}
