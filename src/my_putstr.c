/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Displays all the char of a str
*/

#include <unistd.h>
#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 1;
}
