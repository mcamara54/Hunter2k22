/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** ch_all
*/

#include "../include/hunter.h"

static void ch_menu(hunt_t *g)
{
    if (on_button(g->m[1], g)) {
        g->plan = GAME;
        return;
    }
    g->m[1]->rect.left = 0;
    sfSprite_setTextureRect(g->m[1]->sprite, g->m[1]->rect);
    if (on_button(g->m[2], g)) {
        sfRenderWindow_close(g->window);
        return;
    }
}

static void birds_touched(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        if (on_button(t->bird, g))
            t->health -= 10;
        t = t->next;
    }
}

static void ch_game(hunt_t *g)
{
    birds_touched(g);
}

void ch_all(hunt_t *g)
{
    if (g->event.type == sfEvtClosed)
        sfRenderWindow_close(g->window);

    (g->plan == MENU ? on_menu(g) : 0);
    if (g->event.type == sfEvtMouseButtonReleased) {
        (g->plan == MENU ? ch_menu(g) : ch_game(g));
    }
}
