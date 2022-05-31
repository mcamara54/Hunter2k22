/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** on_menu
*/

#include "../include/hunter.h"

void on_menu(hunt_t *g)
{
    if (on_button(g->m[1], g)) {
        g->m[1]->rect.left = 383;
        sfSprite_setTextureRect(g->m[1]->sprite, g->m[1]->rect);
        return;
    }
    g->m[1]->rect.left = 0;
    sfSprite_setTextureRect(g->m[1]->sprite, g->m[1]->rect);
    if (on_button(g->m[2], g)) {
        g->m[2]->rect.left = 326;
        sfSprite_setTextureRect(g->m[2]->sprite, g->m[2]->rect);
        return;
    }
    g->m[2]->rect.left = 0;
    sfSprite_setTextureRect(g->m[2]->sprite, g->m[2]->rect);
}
