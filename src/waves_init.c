/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** waves_init
*/

#include "../include/hunter.h"

static birds_t *mputin_birds(birds_t *list)
{
    birds_t *element = malloc(sizeof(birds_t));
    element->bird = create_obj("assets/birds.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 60, 70}, (sfVector2f) {1.3, 1.3});
    element->attack = 3;
    element->health = rand() % 16;
    (!element->health ? element->health = 1 : 0);
    element->next = list;
    return (element);
}

static birds_t *mputin_boss(birds_t *list)
{
    birds_t *element = malloc(sizeof(birds_t));
    element->bird = create_obj("assets/birds.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 60, 70}, (sfVector2f) {2, 2});
    element->attack = 6;
    element->health = 30;
    element->next = list;
    return (element);
}

static void place_birds(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        t->bird->pos = (sfVector2f) {2000, rand() % 750};
        sfSprite_setPosition(t->bird->sprite, t->bird->pos);
        t = t->next;
    }
}

void waves_init(hunt_t *g, int a)
{
    for (; a; a--) {
        if (!(a % 5))
            g->b = mputin_boss(g->b);
        else
            g->b = mputin_birds(g->b);
    } place_birds(g);
}
