/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** hunter
*/

#ifndef HUNTER_H_
    #define HUNTER_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Network.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>

enum scene {
    MENU = 1,
    GAME = 2,
    NOTHING = 0,
};

struct class_object
{
    sfTexture *tex;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
};
typedef struct class_object game_obj_t;

struct birds
{
    int health;
    int attack;

    game_obj_t *bird;
    struct birds *next;
};
typedef struct birds birds_t;

struct hunter
{
    int plan;
    int side;
    int top;
    int waves;
    sfRenderWindow *window;
    sfWindow *win;
    sfVideoMode mode;
    sfVector2i mouse;
    sfVector2f pos_mouse;
    sfEvent event;
    sfView *cam;
    game_obj_t *m[3];
    game_obj_t *g[2];
    birds_t *b;
    sfClock *clock;
    sfTime time;
    float sec;
};
typedef struct hunter hunt_t;

#include "proto.h"

#endif /* !HUNTER_H_ */
