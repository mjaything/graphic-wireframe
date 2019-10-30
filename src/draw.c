/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:12 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 06:01:28 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

static void	put_pixel(t_env *env, int x, int y, int color)
{
	int i;

	if (x >= INSTRUCTION_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
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
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
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
		if (i % WIDTH < INSTRUCTION_WIDTH)
			background[i] = COLOR_INSTRUCTION_WHITE;
		else
			background[i] = COLOR_BACKGROUND_ROSE_WHITE;
		i++;
	}
}

void		draw_instruction(t_env *env)
{
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;

	y = 0;
	mlx_ptr = env->mlx_ptr;
	win_ptr = env->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 65, y += 20, COLOR_TEXT_BLACK,
			"FdF Instruction");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 35, COLOR_TEXT_BLACK,
			"Zoom Camera: Scroll or +, -");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, COLOR_TEXT_BLACK,
			"Move Camera: Arrow Keys");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, COLOR_TEXT_BLACK,
			"Flatten Camera: <, >");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, COLOR_TEXT_BLACK,
			"Rotate Camera: Click Mouse and Move");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 25, COLOR_TEXT_BLACK,
			"- X Axis: 2, 8");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 25, COLOR_TEXT_BLACK,
			"- Y Axis: 4, 6");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 25, COLOR_TEXT_BLACK,
			"- Z Axis: 1, 3, 7, 9");
	mlx_string_put(mlx_ptr, win_ptr, 15, y += 30, COLOR_TEXT_BLACK,
			"Projection: I(Isometric), P(Parallel)");
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
	draw_instruction(env);
}
