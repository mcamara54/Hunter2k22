/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** ch_mouse
*/

#include "../include/hunter.h"

int on_button(game_obj_t *button, hunt_t *g)
{
    g->mouse = sfMouse_getPositionRenderWindow(g->window);
    if (g->mouse.x > button->pos.x && g->mouse.x <
    button->pos.x + button->rect.width * button->scale.x) {
        if (g->mouse.y > button->pos.y && g->mouse.y <
        button->pos.y + button->rect.height * button->scale.y) {
            return (1);
        }
    }
    return (0);
}
