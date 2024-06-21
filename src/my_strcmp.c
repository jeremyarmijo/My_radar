/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays the number
*/
#include "my.h"

int my_strcmp(char *str, char *list)
{
    int i = 0;

    if (my_strlen(str) != my_strlen(list)){
        return -1;
    }
    while (str[i] != '\0'){
        if ((str[i] - list[i]) > 0){
            return -1;
        }
        if ((str[i] - list[i]) < 0) {
            return -1;
        }
        i++;
    }
    return 0;
}
