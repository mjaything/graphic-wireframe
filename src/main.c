#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int     			fd;
    t_map   			*map;
	t_env				*env;
	t_matrix_element	*matrix_element_stack;

    errno = 0;
    if (argc == 2)
    {
        if (!(fd = open(argv[1], O_RDONLY)) >= 0))
            terminate(ERR_MAP_OPENING);
        map = map_init();
        if (load_map(fd, &matrix_element_stack, map) == -1)
            terminate(ERR_MAP_LOADING);
        env = env_init(map);
		transform_to_array(&matrix_element_stack, map);
        env->camera = camera_init(env);
		draw(env->map, env);

		mlx_loop(env->mlx);
    }
    terminate(ERR_USAGE);
    return (0);
}

void	terminate(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}
