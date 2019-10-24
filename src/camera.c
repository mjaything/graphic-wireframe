#include "fdf.h"

void	switch_camera_projection(int key, t_env *env)
{
    env->camera->alpha = 0;
    env->camera->beta = 0;
    env->camera->gamma = 0;
    if (key == KEYBOARD_MAIN_I)
        env->camera->projection = isometric;
    if (key == KEYBOARD_MAIN_P)
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
    if (key == KEYBOARD_MAIN_PLUS ||
        key == KEYBOARD_NUM_PLUS ||
        key == MOUSE_SCROLL_UP)
        env->camera->zoom++;
    else if (key == KEYBOARD_MAIN_MINUS ||
            key == KEYBOARD_NUM_MINUS || 
            key == MOUSE_SCROLL_DOWN)
        env->camera->zoom--;
    if (env->camera->zoom < 1)
        env->camera->zoom = 1;
    draw(env->map, env);
}

void	rotate_camera(int key, t_env *env)
{
    if (key == KEYBOARD_MAIN_2 || KEYBOARD_NUM_2)
        env->camera->alpha += 0.05;
    else if (KEYBOARD_MAIN_8 || KEYBOARD_NUM_8)
        env->camera->alpha -= 0.05;
    else if (KEYBOARD_MAIN_4 || KEYBOARD_NUM_4)
        env->camera->beta -= 0.05;
    else if (KEYBOARD_MAIN_6 || KEYBOARD_NUM_6)
        env->camera->beta += 0.05;
    else if (KEYBOARD_MAIN_1 || KEYBOARD_NUM_1 ||
            KEYBOARD_MAIN_3 || KEYBOARD_NUM_3)
        env->camera->gamma += 0.05;
    else if (KEYBOARD_MAIN_7 || KEYBOARD_NUM_7 ||
            KEYBOARD_MAIN_9 || KEYBOARD_NUM_9)
        env->camera->gamma -= 0.05;
    draw(env->map, env);
}

void	flatten_camera(int key, t_env *env)
{
    if (key == KEYBOARD_MAIN_MORE)
        env->camera->z_divisor += 0.1;
    else if (key == KEYBOARD_MAIN_LESS)
        env->camera->z_divisor -= 0.1;
    if (env->camera->z_divisor > 10)
        env->camera->z_divisor = 10;
    else if (env->camera->z_divisor < 0.1)
        env->camera->z_divisor = 0.1;
    draw(env->map, env);
}