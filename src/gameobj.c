/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** gameobj
*/

#include "../include/hunter.h"

struct class_object *create_obj(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    game_obj_t *create = malloc(sizeof(game_obj_t));
    create->tex = sfTexture_createFromFile(path_to_spritesheet, NULL);
    create->sprite = sfSprite_create();
    create->rect = rect;
    create->pos = pos;
    create->scale = scale;
    sfSprite_setTexture(create->sprite, create->tex, sfTrue);
    sfSprite_setTextureRect(create->sprite, create->rect);
    sfSprite_setPosition(create->sprite, create->pos);
    sfSprite_setScale(create->sprite, create->scale);
    return (create);
}
