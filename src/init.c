#include "fdf.h"

t_env   *env_init(t_map *map)
{
    t_env   *env;

    if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
        terminate(ERR_ENV_INIT_MEMALLOC);
    if (!(env->mlx = mlx_init()))
        terminate(ERR_ENV_INIT_MLX);
    if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FdF")))
        terminate(ERR_ENV_INIT_WIN);
    if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
        terminate(ERR_ENV_INIT_IMG);
    env->data_addr = mlx_get_data_addr(env->img, &(env->bits_per_pixel), &(env->size_line), &(env->endian));
    env->map = map;
    if(!(env->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
        terminate(ERR_ENV_INIT_MOUSE);
    return (env);
}

t_map   *map_init(void)
{
    t_map   *map;

    if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
        terminate(ERR_MAP_INIT);
    map->width = 0;
    map->height = 0;
    map->matrix_elements_arr = NULL;
    map->colors_arr = NULL;
    map->z_max = 
    map->z_min = 
    map->z_range = 0;
    return (map);
}
