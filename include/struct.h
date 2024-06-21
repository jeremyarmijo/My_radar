/*
** EPITECH PROJECT, 2023
** struct
** File description:
** hunter
*/
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include <SFML/Window.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/ConvexShape.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Transformable.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <stdlib.h>
#ifndef S_H
    #define S_H
    #define PIC_1 ALL->pictures[0].sprite
    #define MODV_1 ALL->settings.mode
    #define WIN_1 ALL->settings.window
    #define TOWS_1 obj->tower[i].sprite
    #define INIT_1 (*hitbox)[i].shape
    #define INIT_2 INFO_OBJ_T *obj

typedef struct PARAMETER {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    int img_n;
}PARAMETER_T;

typedef struct hitbox {
    sfVector2f position;
    sfVector2f size;
    sfRectangleShape *shape;
}HITBOX_T;

typedef struct IMG {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos_start;
    sfVector2f pos_arrive;
    int speed;
    int delay;
    sfVector2f origin;
    int trajectoire_x;
    int trajectoire_y;
    int trav_finish_x;
    int trav_finish_y;
    int my_bool;
}IMG_T;

typedef struct TOWER {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f position_c;
    sfVector2f positiont;
    sfCircleShape* circle;
    int radius;
}TOWER_T;

typedef struct info_obj_s {
    int nb_tower;
    int nb_plane;
    IMG_T *plane;
    TOWER_T *tower;
}INFO_OBJ_T;

typedef struct GLOBAL {
    PARAMETER_T settings;
    IMG_T *pictures;
}GLOBAL_T;

typedef struct open_s {
    sfVideoMode video_mode;
    sfEvent event;
    sfColor sfBlack;
}open_t;

#endif
