/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

int my_putchar2(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar2(nb + '0');
    } else if (nb < 0) {
        my_putchar2('-');
        my_put_nbr(nb * (- 1));
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
        }
    return 0;
}
