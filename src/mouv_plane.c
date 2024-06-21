/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void mouv_right_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox, int i)
{
    if (obj->plane[i].pos_start.x > obj->plane[i].pos_arrive.x
    && obj->plane[i].trajectoire_x == 0)
        obj->plane[i].trajectoire_x = 1;
    if (obj->plane[i].trajectoire_x == 1
    && obj->plane[i].trav_finish_x != -1) {
        obj->plane[i].pos_start.x -= obj->plane[i].speed;
        hitbox[i].position.x -= obj->plane[i].speed;
    }
    if (obj->plane[i].trajectoire_x == 1
    && obj->plane[i].pos_start.x < obj->plane[i].pos_arrive.x) {
        obj->plane[i].trav_finish_x = -1;
    }
}

void mouv_down_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox, int i)
{
    if (obj->plane[i].pos_start.y < obj->plane[i].pos_arrive.y
    && obj->plane[i].trajectoire_y == 0)
        obj->plane[i].trajectoire_y = 1;
    if (obj->plane[i].trajectoire_y == 1
    && obj->plane[i].trav_finish_y != -1) {
        obj->plane[i].pos_start.y += obj->plane[i].speed;
        hitbox[i].position.y += obj->plane[i].speed;
    }
    if (obj->plane[i].trajectoire_y == 1
    && obj->plane[i].pos_start.y > obj->plane[i].pos_arrive.y) {
        obj->plane[i].trav_finish_y = -1;
    }
}

void mouv_left_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox, int i)
{
    if (obj->plane[i].pos_start.x < obj->plane[i].pos_arrive.x
    && obj->plane[i].trajectoire_x == 0)
        obj->plane[i].trajectoire_x = 2;
    if (obj->plane[i].trajectoire_x == 2
    && obj->plane[i].trav_finish_x != -2) {
        obj->plane[i].pos_start.x += obj->plane[i].speed;
        hitbox[i].position.x += obj->plane[i].speed;
    }
    if (obj->plane[i].trajectoire_x == 2
    && obj->plane[i].pos_start.x > obj->plane[i].pos_arrive.x) {
        obj->plane[i].trav_finish_x = -2;
    }
}

void mouv_up_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox, int i)

{
    if (obj->plane[i].pos_start.y > obj->plane[i].pos_arrive.y
    && obj->plane[i].trajectoire_y == 0) {
        obj->plane[i].trajectoire_y = 2;
    }
    if (obj->plane[i].trajectoire_y == 2 &&
    obj->plane[i].trav_finish_y != -2) {
        obj->plane[i].pos_start.y -= obj->plane[i].speed;
        hitbox[i].position.y -= obj->plane[i].speed;
    }
    if (obj->plane[i].trajectoire_y == 2
    && obj->plane[i].pos_start.y < obj->plane[i].pos_arrive.y) {
        obj->plane[i].trav_finish_y = -2;
    }
}

void mouv_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox)
{
    for (int i = 0; i < obj->nb_plane &&
        obj->plane[i].speed != 0; i++){
        mouv_right_plane(obj, hitbox, i);
        mouv_down_plane(obj, hitbox, i);
        mouv_left_plane(obj, hitbox, i);
        mouv_up_plane(obj, hitbox, i);
        if (obj->plane[i].pos_start.x == obj->plane[i].pos_arrive.x
        && obj->plane[i].pos_start.y == obj->plane[i].pos_arrive.y)
            obj->plane[i].my_bool = 1;
    }
}
