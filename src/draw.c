/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:12 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/30 22:58:56 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

static void	put_pixel(t_env *env, int x, int y, int color)
{
	int i;

	if (x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bits_per_pixel / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

static void	draw_line(t_point a, t_point b, t_env *env)
{
	t_point delta;
	t_point sign;
	t_point cur;
	int		error[2];

	delta.x = ABS_VAL(b.x - a.x);
	delta.y = ABS_VAL(b.y - a.y);
	sign.x = b.x > a.x ? 1 : -1;
	sign.y = b.y > a.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(env, cur.x, cur.y, get_final_color(cur, a, b, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void	draw_background_color(t_env *env)
{
	int *background;
	int i;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bits_per_pixel / 8));
	background = (int *)(env->data_addr);
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		background[i] = COLOR_BACKGROUND_ROSE_WHITE;
		i++;
	}
}

void		draw(t_map *map, t_env *env)
{
	int x;
	int y;

	draw_background_color(env);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != env->map->width - 1)
				draw_line(project_2d(new_point(x, y, map), env),
						project_2d(new_point(x + 1, y, map), env), env);
			if (y != env->map->height - 1)
				draw_line(project_2d(new_point(x, y, map), env),
						project_2d(new_point(x, y + 1, map), env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
