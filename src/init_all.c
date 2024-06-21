/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void init_win(GLOBAL_T *ALL)
{
    ALL->settings.mode.width = 1920;
    ALL->settings.mode.height = 1080;
    ALL->settings.mode.bitsPerPixel = 32;
    WIN_1 = sfRenderWindow_create(MODV_1, "My Radar", sfDefaultStyle, NULL);
}

void init_background(GLOBAL_T *ALL)
{
    ALL->pictures = malloc(sizeof(IMG_T));
    ALL->pictures[0].texture = sfTexture_createFromFile("src/carte.jpg", NULL);
    ALL->pictures[0].sprite = sfSprite_create();
    sfSprite_setTexture(PIC_1, ALL->pictures[0].texture, sfFalse);
}

void init_obj(INFO_OBJ_T *obj, char **info, HITBOX_T **hitbox)
{
    init_plane(info, obj);
    init_tower(info, obj);
    init_hitbox(hitbox, obj);
}

void init_all(GLOBAL_T *ALL, INIT_2, char **info, HITBOX_T **hitbox)
{
    init_win(ALL);
    init_background(ALL);
    init_obj(obj, info, hitbox);
}
