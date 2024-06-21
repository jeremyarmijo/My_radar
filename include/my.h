/*
** EPITECH PROJECT, 2023
** header
** File description:
** f
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
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include "struct.h"

#ifndef F_H
    #define F_H


void delete_plane(INFO_OBJ_T *obj, int i);
void close_win(GLOBAL_T *ALL, sfEvent *event);
void mouv_plane(INFO_OBJ_T *obj, HITBOX_T *hitbox);
void refresh_pos_draw(INFO_OBJ_T *obj, HITBOX_T *hitbox, GLOBAL_T *ALL);
int game(char **info);
int to_number(char *str);
int nb_obj(char **av, char c);
void init_all(GLOBAL_T *ALL, INFO_OBJ_T *obj, char **info, HITBOX_T **hitbox);
void init_hitbox(HITBOX_T **hitbox, INFO_OBJ_T *obj);
void init_tower(char **info, INFO_OBJ_T *obj);
void set_spritetower(INFO_OBJ_T *obj, int i);
void set_cicle(INFO_OBJ_T *obj, int i);
void init_plane(char **info, INFO_OBJ_T *obj);
void set_spriteplana(INFO_OBJ_T *obj, int i);
void init_background(GLOBAL_T *ALL);
void init_win(GLOBAL_T *ALL);
void init_obj(INFO_OBJ_T *obj, char **info, HITBOX_T **hitbox);
void my_putchar(char c);
int my_putstr(char const *str);
int error_char_script(char *script);
char *fill_script(char *av, struct stat *info_script);
int error_script(char **info);
int error_nb_info_script(char **info, int i);
int nb_of_nb(char const *str);
int nb_char_reset(int i, int cpt2, int nb_char, int previous_char);
int my_strlen_nb_line(char const *str);
int my_strlen_nb_char(char const *str);
char **complet_string(char const *str, char **stringsplit);
char **split_string(char const *str);
void put_h(void);
void print_er(void);
sfCircleShape *create_circle(sfVector2f position, float radius);
int my_strcmp(char *str, char *list);
int my_strlen(char *str);

#endif
