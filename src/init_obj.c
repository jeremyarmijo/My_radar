/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void set_cicle(INFO_OBJ_T *obj, int i)
{
    obj->tower[i].circle = sfCircleShape_create();
    sfCircleShape_setRadius(obj->tower[i].circle, obj->tower[i].radius);
    sfCircleShape_setFillColor(obj->tower[i].circle, sfTransparent);
    sfCircleShape_setPosition(obj->tower[i].circle, obj->tower[i].position_c);
    sfCircleShape_setOutlineThickness(obj->tower[i].circle, 1);
}

void set_spritetower(INFO_OBJ_T *obj, int i)
{
        obj->tower[i].scale.x = 0.05;
        obj->tower[i].scale.y = 0.05;
        obj->tower[i].texture = sfTexture_createFromFile("src/tower.png", NULL);
        obj->tower[i].sprite = sfSprite_create();
        sfSprite_setTexture(TOWS_1, obj->tower[i].texture, sfTrue);
        sfSprite_setScale(obj->tower[i].sprite, obj->tower[i].scale);
        sfSprite_setPosition(obj->tower[i].sprite, obj->tower[i].positiont);
}

void init_tower(char **info, INFO_OBJ_T *obj)
{
    int index = 0;

    obj->nb_tower = nb_obj(info, 'T');
    obj->tower = malloc(sizeof(TOWER_T) * (obj->nb_tower + 1));
    index = obj->nb_plane;
    for (int i = 0; i < obj->nb_tower; i++){
        obj->tower[i].positiont.x = to_number(info[index]);
        obj->tower[i].positiont.y = to_number(info[index]);
        obj->tower[i].radius = to_number(info[index]);
        set_spritetower(obj, i);
        obj->tower[i].position_c.x = obj->tower[i].positiont.x
        - ((obj->tower[i].radius - 2) - (20 / 2));
        obj->tower[i].position_c.y = obj->tower[i].positiont.y
        - ((obj->tower[i].radius - 2) - (20 / 2));
        set_cicle(obj, i);
        index++;
    }
}

void init_hitbox(HITBOX_T **hitbox, INFO_OBJ_T *obj)
{
        *hitbox = malloc(sizeof(HITBOX_T) * (obj->nb_plane + 1));
        for (int i = 0; i < obj->nb_plane; i++) {
            (*hitbox)[i].shape = sfRectangleShape_create();
            (*hitbox)[i].position.x = obj->plane[i].pos_start.x;
            (*hitbox)[i].position.y = obj->plane[i].pos_start.y;
            (*hitbox)[i].size.x = 20;
            (*hitbox)[i].size.y = 20;
            sfRectangleShape_setSize((*hitbox)[i].shape, (*hitbox)[i].size);
            sfRectangleShape_setPosition(INIT_1, (*hitbox)[i].position);
            sfRectangleShape_setOutlineColor((*hitbox)[i].shape, sfWhite);
            sfRectangleShape_setOutlineThickness((*hitbox)[i].shape, 1);
            sfRectangleShape_setFillColor((*hitbox)[i].shape, sfTransparent);
        }
}
