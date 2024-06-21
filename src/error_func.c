/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

int nb_of_nb(char const *str)
{
    int i = 0;
    int nbr = 0;

    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == ' ')
            nbr++;
        i++;
    }
    return nbr;
}

int error_nb_info_script(char **info, int i)
{
    int nb_nb = 0;

    if (info[i][0] == 'A'){
        nb_nb = nb_of_nb(info[i]);
        if (nb_nb != 6)
            return 84;
    }
    if (info[i][0] == 'T') {
        nb_nb = nb_of_nb(info[i]);
        if (nb_nb != 3)
            return 84;
    }
    return 0;
}

int error_script(char **info)
{
    int error = 0;

    for (int i = 0; info[i] != 0; i++){
        error = error_nb_info_script(info, i);
        if (error == 84)
            return 84;
    }
    return error;
}

char *fill_script(char *av, struct stat *info_script)
{
    int fd = 0;
    char *script = malloc(sizeof(char) * (info_script->st_size + 1));

    fd = open(av, O_RDONLY);
    read(fd, script, info_script->st_size);
    script[info_script->st_size] = '\0';
    return script;
}

int error_char_script(char *script)
{
    for (int i = 0; script[i] != '\0'; i++) {
        if (script[i] < '0' && script[i] != ' ' && script[i] != '\n')
            return 84;
        if (script[i] > '9' && script[i] != 'A' && script[i] != 'T')
            return 84;
    }
    return 0;
}
