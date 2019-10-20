#include "fdf.h"

void    choose_projection(int key, t_env *env)
{
    // env->camera->alpha = 0;
    // env->camera->beta = 0;
    // env->camera->gamma = 0;
    if (key == KEYBOARD_I)
        env->camera->projection = PROJECTION_ISOMETRIC;
    if (key == KEYBOARD_P)
        env->camera->projection = PROJECTION_PARALLEL;
}