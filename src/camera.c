#include "fdf.h"

void    choose_projection(int key, t_env *env)
{
    // env->camera->alpha = 0;
    // env->camera->beta = 0;
    // env->camera->gamma = 0;
    if (key == KEYBOARD_MAIN_PAD_I)
        env->camera->projection = ISOMETRIC;
    if (key == KEYBOARD_MAIN_PAD_P)
        env->camera->projection = PARALLEL;
}