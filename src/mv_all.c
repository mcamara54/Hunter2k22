/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** mv_all
*/

#include "../include/hunter.h"

static void mv_birds_animation(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        if (g->sec > 0.1) {
            sfClock_restart(g->clock);
            t->bird->rect.left += 75;
            (t->bird->rect.left >= 600 ? t->bird->rect.left = 0 : 0);
            sfSprite_setTextureRect(t->bird->sprite, t->bird->rect);
        }
        t = t->next;
    }
}

static void mv_birds_deplacement(hunt_t *g)
{

}

void mv_all(hunt_t *g)
{
    mv_birds_animation(g);
    mv_birds_deplacement(g);
}
