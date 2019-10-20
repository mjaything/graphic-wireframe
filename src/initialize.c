#include "fdf.h"

t_map   *initialize_map(void)
{
    t_map   *map;

    if ( )
    {

    }
    map->width = 0;
    map->height = 0;
    //
    return map;
}

t_env   *initialize_env(t_map *map)
{
    t_env   *env;

    if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
        //
    if (!(env->mlx = mlx_init()))
        //
    if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Env")))
        //
    if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT))
        //
    //
    env->map = map;
    if (!(env->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
        //
    return (env);
}

t_camera    *initialize_camera(t_env *env)
{
    t_camera    *camera;

    if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
        //
    // camera->zoom = 
    camera->alpha = 0;
    camera->beta = 0;
    
    return camera;
}