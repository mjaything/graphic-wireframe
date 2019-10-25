/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:30 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 05:41:14 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

static void	rotate_x_axis(int *y, int *z, double alpha)
{
	int old_y;

	old_y = *y;
	*y = (old_y * cos(alpha)) + (*z * sin(alpha));
	*z = (-old_y * sin(alpha)) + (*z * cos(alpha));
}

static void	rotate_y_axis(int *x, int *z, double beta)
{
	int old_x;

	old_x = *x;
	*x = (old_x * cos(beta)) + (*z * sin(beta));
	*z = (-old_x * sin(beta)) + (*z * cos(beta));
}

static void	rotate_z_axis(int *x, int *y, double gamma)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x * cos(gamma)) - (old_y * sin(gamma));
	*y = (old_x * sin(gamma)) + (old_y * cos(gamma));
}

static void	transform_to_isometric_projection(int *x, int *y, int z)
{
	int old_x;
	int old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = -z + (old_x + old_y) * sin(0.523599);
}

t_point		project_2d(t_point p, t_env *env)
{
	p.x *= env->camera->zoom;
	p.y *= env->camera->zoom;
	p.z *= env->camera->zoom / env->camera->z_divisor;
	p.x -= (env->map->width * env->camera->zoom) / 2;
	p.y -= (env->map->height * env->camera->zoom) / 2;
	rotate_x_axis(&p.y, &p.z, env->camera->alpha);
	rotate_y_axis(&p.x, &p.z, env->camera->beta);
	rotate_z_axis(&p.x, &p.y, env->camera->gamma);
	if (env->camera->projection == isometric)
		transform_to_isometric_projection(&p.x, &p.y, p.z);
	p.x += ((WIDTH - INSTRUCTION_WIDTH) / 2) + env->camera->x_offset
		+ INSTRUCTION_WIDTH;
	p.y += (HEIGHT + env->map->height * env->camera->zoom) / 2
		+ env->camera->y_offset;
	return (p);
}
