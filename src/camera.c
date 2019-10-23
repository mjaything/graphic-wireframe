#include "fdf.h"

void	switch_camera_projection(int key, t_env *env)
{
    env->camera->alpha = 0;
    env->camera->beta = 0;
    env->camera->gamma = 0;
    if (key == KEYBOARD_MAIN_PAD_I)
        env->camera->projection = isometric;
    if (key == KEYBOARD_MAIN_PAD_P)
        env->camera->projection = parallel;
}

void	move_camera(int key, t_env *env)
{
    if (key == KEYBOARD_ARROW_LEFT)
        env->camera->x_offset -= 10;
    else if (key == KEYBOARD_ARROW_RIGHT)
        env->camera->x_offset += 10;
    else if (key == KEYBOARD_ARROW_UP)
        env->camera->y_offset -= 10;
    else
        env->camera->y_offset += 10;
    draw(env->map, env);
}

void	zoom_camera(int key, t_env *env)
{
    if (key == KEYBOARD_MAIN_PAD_PLUS ||
        key == KEYBOARD_NUM_PAD_PLUS ||
        key == MOUSE_SCROLL_UP)
        env->camera->zoom++;
    else if (key == KEYBOARD_MAIN_PAD_MINUS ||
            key == KEYBOARD_NUM_PAD_MINUS || 
            key == MOUSE_SCROLL_DOWN)
        env->camera->zoom--;
    if (env->camera->zoom < 1)
        env->camera->zoom = 1;
    draw(env->map, env);
}

void	rotate_camera(int key, t_env *env)
{
    if (key == KEYBOARD_MAIN_PAD_2 || KEYBOARD_NUM_PAD_2)
        env->camera->alpha += 0.05;
    else if (KEYBOARD_MAIN_PAD_8 || KEYBOARD_NUM_PAD_8)
        env->camera->alpha -= 0.05;
    else if (KEYBOARD_MAIN_PAD_4 || KEYBOARD_NUM_PAD_4)
        env->camera->beta -= 0.05;
    else if (KEYBOARD_MAIN_PAD_6 || KEYBOARD_NUM_PAD_6)
        env->camera->beta += 0.05;
    else if (KEYBOARD_MAIN_PAD_1 || KEYBOARD_NUM_PAD_1 ||
            KEYBOARD_MAIN_PAD_3 || KEYBOARD_NUM_PAD_3)
        env->camera->gamma += 0.05;
    else if (KEYBOARD_MAIN_PAD_7 || KEYBOARD_NUM_PAD_7 ||
            KEYBOARD_MAIN_PAD_9 || KEYBOARD_NUM_PAD_9)
        env->camera->gamma -= 0.05;
    draw(env->map, env);
}

void	flatten_camera(int key, t_env *env)
{
    if (key == KEYBOARD_MAIN_PAD_MORE)
        env->camera->z_divisor += 0.1;
    else if (key == KEYBOARD_MAIN_PAD_LESS)
        env->camera->z_divisor -= 0.1;
    if (env->camera->z_divisor > 10)
        env->camera->z_divisor = 10;
    else if (env->camera->z_divisor < 0.1)
        env->camera->z_divisor = 0.1;
    draw(env->map, env);
}