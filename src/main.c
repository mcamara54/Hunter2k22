/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** main
*/

#include "../include/hunter.h"

static void variables(hunt_t *g)
{
    srand(time(NULL));
    g->plan = MENU;
    g->waves = 1;
    g->top = 1080;
    g->side = 1920;
}

static void structures(hunt_t *g)
{
    g->b = NULL;
    waves_init(g, g->waves);
    g->clock = sfClock_create();
}

static void window(hunt_t *g)
{
    g->mode = (sfVideoMode) {1920, 1080, 32};
    g->window = sfRenderWindow_create(g->mode, "vy_Hunter",
    sfResize | sfClose, NULL);
}

int main(int ac, char **av)
{
    hunt_t *g = malloc(sizeof(hunt_t));
    void (*p[]) (hunt_t *) = {variables, structures, window, NULL};
    for (int a = 0; *p[a]; a++) (*p[a])(g);
    gloop(g);
    free(g);
    return (0);
}
