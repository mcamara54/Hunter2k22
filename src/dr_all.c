/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** dr_all
*/

#include "../include/hunter.h"

static void dr_birds(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        if (t->health > 0)
            sfRenderWindow_drawSprite(g->window, t->bird->sprite, NULL);
        t = t->next;
    }
}

void dr_all(hunt_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);

    if (g->plan == MENU) {
        sfRenderWindow_drawSprite(g->window, g->m[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->m[1]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->m[2]->sprite, NULL);
    } if (g->plan == GAME) {
        sfRenderWindow_drawSprite(g->window, g->g[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->g[1]->sprite, NULL);
        dr_birds(g);
    }

    sfRenderWindow_display(g->window);
}
