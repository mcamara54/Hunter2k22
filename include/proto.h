/*
** EPITECH PROJECT, 2022
** Hunter2k22
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

void gloop(hunt_t *g);
void ch_all(hunt_t *g);
void dr_all(hunt_t *g);
void de_all(hunt_t *g);
void mv_all(hunt_t *g);
void on_menu(hunt_t *g);

struct class_object *create_obj(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale);
int on_button(game_obj_t *button, hunt_t *g);

void waves_init(hunt_t *g, int a);
void waves_checker(hunt_t *g);

#endif /* !PROTO_H_ */
