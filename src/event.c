/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:36:47 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/24 20:36:48 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

int 	close(void *param)
{
    (void)param;
    exit(0);
}

void    setup_events(t_env *env)
{
    mlx_hook(env->win_ptr, 2, 0, press_key, env);
    mlx_hook(env->win_ptr, 17, 0, close, env);
    mlx_hook(env->win_ptr, 4, 0, click_mouse, env);
    mlx_hook(env->win_ptr, 5, 0, release_mouse, env);
    mlx_hook(env->win_ptr, 6, 0, move_mouse, env);
}
