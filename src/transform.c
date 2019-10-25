/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 05:47:03 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/25 05:59:37 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	transform_stack_to_array(t_matrix_element **matrix_element_stack,
		t_map *map)
{
	t_matrix_element	*matrix_element;
	size_t				arr_size;
	size_t				i;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->matrix_element_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_TRANSFORM_TO_ARRAY);
	if (!(map->color_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_TRANSFORM_TO_COLOR_ARRAY);
	i = (map->width * map->height) - 1;
	while ((matrix_element = pop(matrix_element_stack)) && i >= 0)
	{
		map->matrix_element_arr[i] = matrix_element->z;
		map->color_arr[i] = matrix_element->color;
		if (matrix_element->z > map->z_max)
			map->z_max = matrix_element->z;
		if (matrix_element->z < map->z_min)
			map->z_min = matrix_element->z;
		i--;
		free(matrix_element);
	}
	map->z_range = map->z_max - map->z_min;
}
