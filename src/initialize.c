/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:36:51 by min-kim           #+#    #+#             */
/*   Updated: 2019/10/30 22:52:27 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

t_env		*initialize_env(t_map *map)
{
	t_env	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		terminate(ERR_ENV_INIT_MEMALLOC);
	if (!(env->mlx_ptr = mlx_init()))
		terminate(ERR_ENV_INIT_MLX);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FdF")))
		terminate(ERR_ENV_INIT_WIN);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT)))
		terminate(ERR_ENV_INIT_IMG);
	env->data_addr = mlx_get_data_addr(env->img_ptr, &(env->bits_per_pixel),
			&(env->size_line), &(env->endian));
	env->map = map;
	if (!(env->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		terminate(ERR_ENV_INIT_MOUSE);
	return (env);
}

t_map		*initialize_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->matrix_element_arr = NULL;
	map->color_arr = NULL;
	map->z_max = INT_MIN_VAL;
	map->z_min = INT_MAX_VAL;
	map->z_range = 0;
	return (map);
}

t_camera	*initialize_camera(t_env *env)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = MIN_VAL(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divisor = 1;
	return (camera);
}
