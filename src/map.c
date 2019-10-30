/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:37:25 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/30 22:35:02 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <stdlib.h>

static void				free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static t_matrix_element	*new_matrix_element(char *str)
{
	t_matrix_element	*element;
	char				**element_splitted;

	if (!(element = (t_matrix_element *)ft_memalloc(sizeof(t_matrix_element))))
		terminate(ERR_MAP_LOADING);
	if (!(element_splitted = ft_strsplit(str, ',')))
		terminate(ERR_MAP_LOADING);
	if (!is_number(element_splitted[0], 10))
		terminate(ERR_MAP_LOADING);
	if (element_splitted[1] && !is_number(element_splitted[1], 16))
		terminate(ERR_MAP_LOADING);
	element->z = ft_atoi(element_splitted[0]);
	element->color = element_splitted[1] ?
		atoi_base(element_splitted[1], 16) : -1;
	element->next = NULL;
	free_arr(element_splitted);
	return (element);
}

static void				parse_row(char **row_arr,
		t_matrix_element **matrix_element_stack, t_map *map)
{
	int width;

	width = 0;
	while (*row_arr)
	{
		push(matrix_element_stack, new_matrix_element(*(row_arr++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
}

int						load_map(const int fd,
		t_matrix_element **matrix_element_stack, t_map *map)
{
	char	*row;
	char	**row_arr;
	int		result;

	while ((result = get_next_line(fd, &row)) == 1)
	{
		if (!(row_arr = ft_strsplit(row, ' ')))
			terminate(ERR_MAP_LOADING);
		parse_row(row_arr, matrix_element_stack, map);
		free_arr(row_arr);
		ft_strdel(&row);
		map->height++;
	}
	if (!(*matrix_element_stack))
		terminate(ERR_MAP_FILE);
	return (result);
}
