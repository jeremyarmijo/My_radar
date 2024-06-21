/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

int nb_obj(char **av, char c)
{
    int nb_A = 0;

    for (int i = 0; av[i] != 0; i++) {
        if (av[i][0] == c)
            nb_A++;
    }
    return nb_A;
}

void set_spriteplana(INFO_OBJ_T *obj, int i)
{
    obj->plane[i].scale.x = 0.07;
    obj->plane[i].scale.y = 0.07;
    obj->plane[i].texture = sfTexture_createFromFile("src/plane.png", NULL);
    obj->plane[i].sprite = sfSprite_create();
    sfSprite_setTexture(obj->plane[i].sprite, obj->plane[i].texture, sfTrue);
    sfSprite_setScale(obj->plane[i].sprite, obj->plane[i].scale);
    sfSprite_setPosition(obj->plane[i].sprite, obj->plane[i].pos_start);
}

void init_plane(char **info, INFO_OBJ_T *obj)
{
    obj->nb_plane = nb_obj(info, 'A');
    obj->plane = malloc(sizeof(IMG_T) * (obj->nb_plane + 1));
    for (int i = 0; i < obj->nb_plane; i++){
        obj->plane[i].trav_finish_x = 0;
        obj->plane[i].trav_finish_y = 0;
        obj->plane[i].trajectoire_x = 0;
        obj->plane[i].trajectoire_y = 0;
        obj->plane[i].my_bool = 0;
        obj->plane[i].pos_start.x = to_number(info[i]);
        obj->plane[i].pos_start.y = to_number(info[i]);
        obj->plane[i].pos_arrive.x = to_number(info[i]);
        obj->plane[i].pos_arrive.y = to_number(info[i]);
        obj->plane[i].speed = to_number(info[i]);
        obj->plane[i].delay = to_number(info[i]);
        set_spriteplana(obj, i);
    }
}
