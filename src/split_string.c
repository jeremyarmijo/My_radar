/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

int my_strlen_nb_line(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb++;
        i++;
    }
    if (str[i] == '\0' && str[i - 1] != '\n')
        return nb + 1;
    return nb;
}

char **complet_string(char const *str, char **stringsplit)
{
    int c2 = 0;
    int cpt2 = 0;

    for (int cpt = 0; stringsplit[cpt] != 0; cpt++) {
        for (; str[cpt2] != '\n'; cpt2++) {
            stringsplit[cpt][c2] = str[cpt2];
            c2++;
        }
        cpt2++;
        c2 = 0;
    }
    return stringsplit;
}

int nb_char_reset(int i, int cpt2, int nb_char, int previous_char)
{
    if (i == 0)
            previous_char = cpt2;
        else {
            previous_char = cpt2 - nb_char;
        }
    return previous_char;
}

char **split_string(char const *str)
{
    char **stringsplit = NULL;
    int nb_char = 0;
    int nbline = my_strlen_nb_line(str);
    int cpt2 = 0;
    int previous_char = 0;

    stringsplit = malloc((nbline + 1) * (sizeof(char *)));
    for (int i = 0; i < nbline; i++){
        nb_char = cpt2;
        while (str[cpt2] != '\n')
            cpt2++;
        previous_char = nb_char_reset(i, cpt2, nb_char, previous_char);
        stringsplit[i] = malloc((previous_char + 1) * sizeof(char));
        stringsplit[i][previous_char] = '\0';
        cpt2++;
    }
    stringsplit[nbline] = NULL;
    complet_string(str, stringsplit);
    return stringsplit;
}
