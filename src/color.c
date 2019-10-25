/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:36:43 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 05:13:23 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_altitude_percentage(int start, int end, int current)
{
	double	altitude;
	double	total_length;
	double	altitude_percentage;

	altitude = current - start;
	total_length = end - start;
	if (total_length == 0)
		altitude_percentage = 1.0;
	else
		altitude_percentage = altitude / total_length;
	return (altitude_percentage);
}

int		get_basic_color(int z, t_map *map)
{
	double	altitude_percentage;

	altitude_percentage = get_altitude_percentage(map->z_min, map->z_max, z);
	if (altitude_percentage < 0.2)
		return (COLOR_WIRE_LIPSTICK);
	else if (altitude_percentage < 0.4)
		return (COLOR_WIRE_COSMIC);
	else if (altitude_percentage < 0.6)
		return (COLOR_WIRE_MOBSTER);
	else if (altitude_percentage < 0.8)
		return (COLOR_WIRE_CHAMBRAY);
	else
		return (COLOR_WIRE_CALYPSO);
}

int		get_light(int start, int end, double altitude_percentage)
{
	int result;

	result = (int)(((1 - altitude_percentage) * start)
			+ (altitude_percentage * end));
	return (result);
}

int		get_final_color(t_point current, t_point start, t_point end,
		t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	altitude_percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		altitude_percentage = get_altitude_percentage(start.x, end.x,
				current.x);
	else
		altitude_percentage = get_altitude_percentage(start.y, end.y,
				current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, altitude_percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, altitude_percentage);
	blue = get_light(start.color & 0xFF,
			end.color & 0xFF, altitude_percentage);
	return ((red << 16) | (green << 8) | blue);
}
