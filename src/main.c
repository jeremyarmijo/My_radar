/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void close_win(GLOBAL_T *ALL, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(ALL->settings.window, event)) {
        if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        sfRenderWindow_close(ALL->settings.window);
    }
}

int open_script(char *av)
{
    struct stat info_script;
    int statretrn = stat(av, &info_script);
    char *script = NULL;
    char **info;

    if (statretrn == -1)
        return 84;
    script = fill_script(av, &info_script);
    if (script == NULL) {
        return 84;
    }
    info = split_string(script);
    if (error_char_script(script) == 84 || error_script(info) == 84)
        return 84;
    game(info);
    for (int i = 0; info[i] != NULL; i++)
        free(info[i]);
    free(info);
    return 0;
}

int main(int ac, char **av)
{
    int error = 0;

    if (ac != 2){
        print_er();
        return 84;
    }
    if (my_strcmp("-h", av[1]) == 0)
        put_h();
    error = open_script(av[1]);
    if (error == 84)
        return 84;
    return 0;
}
