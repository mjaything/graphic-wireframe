/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:36:38 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/24 20:36:40 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (key == KEYBOARD_MAIN_2 || key == KEYBOARD_NUM_2)
        env->camera->alpha += 0.05;
    else if (key == KEYBOARD_MAIN_8 || key == KEYBOARD_NUM_8)
        env->camera->alpha -= 0.05;
    else if (key == KEYBOARD_MAIN_4 || key == KEYBOARD_NUM_4)
        env->camera->beta -= 0.05;
    else if (key == KEYBOARD_MAIN_6 || key == KEYBOARD_NUM_6)
        env->camera->beta += 0.05;
    else if (key == KEYBOARD_MAIN_1 || key == KEYBOARD_NUM_1 ||
            key == KEYBOARD_MAIN_3 || key == KEYBOARD_NUM_3)
        env->camera->gamma += 0.05;
    else if (key == KEYBOARD_MAIN_7 || key == KEYBOARD_NUM_7 ||
            key == KEYBOARD_MAIN_9 || key == KEYBOARD_NUM_9)
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
