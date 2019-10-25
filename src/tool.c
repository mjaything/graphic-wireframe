/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:36 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 04:59:39 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int		get_index(int x, int y, int width)
{
	int index;

	index = x + (y * width);
	return (index);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point p;
	int		i;

	i = get_index(x, y, map->width);
	p.x = x;
	p.y = y;
	p.z = map->matrix_element_arr[i];
	if (map->color_arr[i] == -1)
		p.color = get_basic_color(p.z, map);
	else
		p.color = map->color_arr[i];
	return (p);
}

void	terminate(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}
