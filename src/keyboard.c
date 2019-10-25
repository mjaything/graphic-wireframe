/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:21 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/24 20:37:22 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int press_key(int key, void *param)
{
    t_env   *env;

    env = (t_env *)param;
    if (key == KEYBOARD_MAIN_ESC)
        exit(0);
    if (key == KEYBOARD_MAIN_PLUS || key == KEYBOARD_NUM_PLUS ||
        key == KEYBOARD_MAIN_MINUS || key == KEYBOARD_NUM_MINUS)
        zoom_camera(key, env);
    else if (key == KEYBOARD_ARROW_LEFT || key == KEYBOARD_ARROW_RIGHT ||
            key == KEYBOARD_ARROW_UP || key == KEYBOARD_ARROW_DOWN)
        move_camera(key, env);
    else if (key == KEYBOARD_MAIN_1 || key == KEYBOARD_NUM_1 ||
            key == KEYBOARD_MAIN_2 || key == KEYBOARD_NUM_2 ||
            key == KEYBOARD_MAIN_3 || key == KEYBOARD_NUM_3 ||
            key == KEYBOARD_MAIN_4 || key == KEYBOARD_NUM_4 ||
            key == KEYBOARD_MAIN_6 || key == KEYBOARD_NUM_6 ||
            key == KEYBOARD_MAIN_7 || key == KEYBOARD_NUM_7 ||
            key == KEYBOARD_MAIN_8 || key == KEYBOARD_NUM_8 ||
            key == KEYBOARD_MAIN_9 || key == KEYBOARD_NUM_9)
        rotate_camera(key, env);
    else if (key == KEYBOARD_MAIN_LESS || key == KEYBOARD_MAIN_MORE)
        flatten_camera(key, env);
    else if (key == KEYBOARD_MAIN_I || key == KEYBOARD_MAIN_P)
        switch_camera_projection(key, env);
    return (0);
}
