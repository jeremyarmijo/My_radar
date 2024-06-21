/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void delete_plane(INFO_OBJ_T *obj, int i)
{
    if (obj->plane[i].trav_finish_x == -1
    && obj->plane[i].trav_finish_y == -1)
        obj->plane[i].my_bool = 1;
    if (obj->plane[i].trav_finish_x == -2
    && obj->plane[i].trav_finish_y == -2)
        obj->plane[i].my_bool = 1;
    if (obj->plane[i].trav_finish_x == -2
    && obj->plane[i].trav_finish_y == -1)
        obj->plane[i].my_bool = 1;
    if (obj->plane[i].trav_finish_x == -1
    && obj->plane[i].trav_finish_y == -2)
        obj->plane[i].my_bool = 1;
}

int nb_plane(INFO_OBJ_T *obj)
{
    int nb = 0;

    for (int i = 0; i < obj->nb_plane; i++)
        nb = nb + obj->plane[i].my_bool;
    return nb;
}

void print_plane(INFO_OBJ_T *obj, GLOBAL_T *ALL, HITBOX_T *hitbox)
{
    for (int i = 0; i < obj->nb_plane; i++){
        delete_plane(obj, i);
        if (obj->plane[i].my_bool == 0) {
            sfRectangleShape_setPosition(hitbox[i].shape, hitbox[i].position);
            sfRenderWindow_drawRectangleShape(ALL->settings.window,
            hitbox[i].shape, NULL);
        }
    }
    for (int i = 0; i < obj->nb_plane; i++){
        if (obj->plane[i].my_bool == 0) {
            sfSprite_setPosition(obj->plane[i].sprite,
            obj->plane[i].pos_start);
            sfRenderWindow_drawSprite(ALL->settings.window,
            obj->plane[i].sprite, NULL);
        }
    }
    if (nb_plane(obj) == obj->nb_plane)
        sfRenderWindow_close(ALL->settings.window);
}

void refresh_pos_draw(INFO_OBJ_T *obj, HITBOX_T *hitbox, GLOBAL_T *ALL)
{
    print_plane(obj, ALL, hitbox);
    for (int i = 0; i < obj->nb_tower; i++){
        sfRenderWindow_drawSprite(ALL->settings.window,
        obj->tower[i].sprite, NULL);
        sfRenderWindow_drawCircleShape(ALL->settings.window,
        obj->tower[i].circle, NULL);
    }
}

int game(char **info)
{
    GLOBAL_T ALL;
    INFO_OBJ_T obj;
    HITBOX_T *hitbox = NULL;
    sfEvent event;

    init_all(&ALL, &obj, info, &hitbox);
    while (sfRenderWindow_isOpen(ALL.settings.window)) {
        close_win(&ALL, &event);
        sfRenderWindow_clear(ALL.settings.window, sfBlack);
        sfRenderWindow_drawSprite(ALL.settings.window,
        ALL.pictures[0].sprite, NULL);
        refresh_pos_draw(&obj, hitbox, &ALL);
        sfRenderWindow_setFramerateLimit(ALL.settings.window, 60);
        mouv_plane(&obj, hitbox);
        sfRenderWindow_display(ALL.settings.window);
    }
    sfRenderWindow_destroy(ALL.settings.window);
    return 0;
}
