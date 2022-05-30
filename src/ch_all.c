/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** ch_all
*/

#include "../include/hunter.h"

static void on_menu(hunt_t *g)
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

int waves_ended(hunt_t *g)
{
    birds_t *t = g->b;
    while (t) {
        if (t->health > 0)
            return (0);
        t = t->next;
    }
    return (1);
}

void waves_clean(hunt_t *g)
{

}

void waves_new(hunt_t *g)
{

}

birds_t *mputin_birds(birds_t *list)
{
    birds_t *element = malloc(sizeof(birds_t));
    element->bird = create_obj("assets/birds.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 60, 70}, (sfVector2f) {1, 1});
    element->attack = 3;
    element->health = rand() % 16;
    element->next = list;
    return (element);
}

birds_t *mputin_boss(birds_t *list)
{
    birds_t *element = malloc(sizeof(birds_t));
    int a = rand() % 5;
    element->bird = create_obj("assets/birds.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 60, 70}, (sfVector2f) {a, a});
    element->attack = 6;
    element->health = 20;
    element->next = list;
    return (element);
}

void place_birds(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        t->bird->pos = (sfVector2f) {rand() % 1500, rand() % 750};
        sfSprite_setPosition(t->bird->sprite, t->bird->pos);
        t = t->next;
    }
}

void waves_init(hunt_t *g, int a)
{
    for (; a; a--) {
        if (!(a % 14))
            g->b = mputin_boss(g->b);
        else
            g->b = mputin_birds(g->b);
    } place_birds(g);
}

void birds_touched(hunt_t *g)
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
