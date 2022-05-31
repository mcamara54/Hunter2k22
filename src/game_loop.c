/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** game_loop
*/

#include "../include/hunter.h"

static void msprites(hunt_t *g)
{
    // Main menu //
    g->m[0] = create_obj("assets/background_menu.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 1920, 1080}, (sfVector2f) {1, 1});
    g->m[1] = create_obj("assets/start_button.png", (sfVector2f) {769, 250},
    (sfIntRect) {0, 0, 383, 200}, (sfVector2f) {1, 1});
    g->m[2] = create_obj("assets/quit_button.png", (sfVector2f) {795, 500},
    (sfIntRect) {0, 0, 326, 161}, (sfVector2f) {1, 0.85});
}

static void gsprites(hunt_t *g)
{
    // Background elements //
    g->g[0] = create_obj("assets/background_game.png", (sfVector2f) {-2, 0},
    (sfIntRect) {0, 0, 1920, 1080}, (sfVector2f) {1, 1});
    g->g[1] = create_obj("assets/canoon.png", (sfVector2f) {125, 700},
    (sfIntRect) {0, 0, 65, 60}, (sfVector2f) {3, 3});

    // Birds will be initialated Ingame at each wave
}

static void cursor(hunt_t *g)
{

}

void waves_checker(hunt_t *g)
{
    g->sec = g->time.microseconds / 100000;
    g->time = sfClock_getElapsedTime(g->clock);

    if (waves_ended(g)) {
        waves_clean(g);
        g->waves += 1;
        waves_init(g, g->waves / 2);
    }
}

void gloop(hunt_t *g)
{
    msprites(g);
    gsprites(g);

    while (sfRenderWindow_isOpen(g->window)) {
        g->mouse = sfMouse_getPositionRenderWindow(g->window);
        cursor(g);
        while (sfRenderWindow_pollEvent(g->window, &g->event)) {
            ch_all(g);
        }
        dr_all(g);
        mv_all(g);
        waves_checker(g);
    }
    de_all(g);
}
