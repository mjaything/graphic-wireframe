#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int     atoi_base(const char *str, int base)
{
    unsigned long 	result;
    int             sign;
	size_t          i;

    result = 0;
    sign = 1;
	i = 0;
    while (is_space(str[i]))
        i++;
    if (base != 10 && !has_prefix(&str[i], base))
        return (false);
    if (base == 2 || base == 16)
        i += 2;
    else if (base == 8)
        i++;
    else if (base == 10 && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (is_digit_base(str[i], base) >= 0)
        result = result * base + is_digit_base(str[i++], base);
    return ((int)(result * sign));
}

int get_index(int x, int y, int width)
{
    int index;

    index = x + (y * width);
    return (index);
}

t_point new_point(int x, int y, t_map *map)
{
    t_point p;
    int     i;

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