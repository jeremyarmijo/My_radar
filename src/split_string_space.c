/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

int my_strlen_nb_linebis(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            nb++;
        i++;
    }
    if (str[i] == '\0' && str[i - 1] != ' ')
        return nb + 1;
    return nb;
}

strlen_t *nb_cptbis(char const *str, int i, strlen_t *cpt)
{
    if (str[i] == ' ') {
        if (cpt->current_chars > cpt->max_chars) {
            cpt->max_chars = cpt->current_chars;
        }
        cpt->current_chars = 0;
    } else {
        cpt->current_chars++;
    }
    return cpt;
}

int my_strlen_nb_charbis(char const *str)
{
    strlen_t *cpt = malloc(sizeof(strlen_t));

    cpt->current_chars = 0;
    cpt->max_chars = 0;
    if (str == NULL) {
        return -1;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        cpt = nb_cptbis(str, i, cpt);
    }
    if (cpt->current_chars > cpt->max_chars) {
        cpt->max_chars = cpt->current_chars;
    }
    return cpt->max_chars;
}

char **complet_stringbis(char const *str, char **stringsplit)
{
    int c2 = 0;
    int cpt2 = 0;

    for (int cpt = 0; stringsplit[cpt] != 0; cpt++) {
        for (; str[cpt2] != ' '; cpt2++) {
            stringsplit[cpt][c2] = str[cpt2];
            c2++;
        }
        cpt2++;
        c2 = 0;
    }
    return stringsplit;
}

static int nb_char_reset(int i, int cpt2, int nb_char, int previous_char)
{
    if (i == 0)
            previous_char = cpt2;
        else {
            previous_char = cpt2 - (nb_char);
        }
    return previous_char;
}

char **split_stringbis(char const *str)
{
    char **stringsplit;
    int nb_char = 0;
    int nbline = my_strlen_nb_linebis(str);
    int cpt2 = 0;
    int previous_char = 0;

    stringsplit = malloc((nbline + 1) * (sizeof(char *)));
    stringsplit[nbline] = 0;
    for (int i = 0; stringsplit[i] != 0; i++){
        nb_char = cpt2;
        while (str[cpt2] != ' '){
            cpt2++;
        }
        previous_char = nb_char_reset(i, cpt2, nb_char, previous_char);
        stringsplit[i] = malloc((previous_char + 1) * sizeof(char));
        stringsplit[i][previous_char] = '\0';
        cpt2++;
    }
    complet_stringbis(str, stringsplit);
    return stringsplit;
}
