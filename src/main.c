#include "fdf.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int     			fd;
    t_env				*env;
    t_map   			*map;
	t_matrix_element	*matrix_element_stack;

    errno = 0;
    matrix_element_stack = NULL;
    if (argc == 2)
    {
        if (!((fd = open(argv[1], O_RDONLY)) >= 0))
            terminate(ERR_MAP_OPENING);
        map = initialize_map();
        if (load_map(fd, &matrix_element_stack, map) == -1)
            terminate(ERR_MAP_LOADING);
        env = initialize_env(map);
		transform_stack_to_array(&matrix_element_stack, map);
        env->camera = initialiaze_camera(env);
		draw(env->map, env);
		setup_events(env);
		mlx_loop(env->mlx_ptr);
    }
    terminate(ERR_USAGE);
    return (0);
}
