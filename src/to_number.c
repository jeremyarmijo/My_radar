/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

int to_number(char *str)
{
    int i = 0;
    int nbr = 0;
    int my_bool = 0;

    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9'){
            nbr = nbr * 10 + str[i] - 48;
            str[i] = ' ';
            my_bool = 1;
        }
        if (my_bool == 1 && str[i + 1] == ' ')
            return nbr;
        if (my_bool == 1 && str[i + 1] == '\0')
            return nbr;
        i++;
    }
    return nbr;
}
