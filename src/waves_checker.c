/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** waves_checker
*/

#include "../include/hunter.h"

static int waves_ended(hunt_t *g)
{
    birds_t *t = g->b;

    while (t) {
        if (t->health > 0)
            return (0);
        t = t->next;
    }
    return (1);
}

void waves_checker(hunt_t *g)
{
    g->sec = g->time.microseconds / 100000;
    g->time = sfClock_getElapsedTime(g->clock);

    if (waves_ended(g)) {
        g->waves += 1;
        waves_init(g, g->waves / 4);
    }
}
