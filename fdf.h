#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos.h"
# include "../libft/libft.h"

# define WIDTH 4000
# define HEIGHT 3000

# define ESC 
# define RIGHT
# define LEFT
# define UP
# define DOWN
# define ZOOMIN
# define ZOOMOUT


typedef struct
{
    int x;
    int y;
    int z;
    // int  size_x;
    // int  size_y;
}   t_point;

typdef struct
{
    // t_point ***point;
    void    *mlx;
    void    *win;
    void    *img;
    // char    *ret;
    int     color;
    int     red;
    int     green;
    int     blue;
    int     depth;
    int     zoom;
    int     opacity;
    int     max_height;
    int     min_height;
    // int  tmpi;
    // int  tmpj;
    // int  tmpz;
    // int  opacity;
    // int  bits_per_pixel;
    // int  size_line;
    // int  endian;
    // unsigned int tight;
    // unsigned int tight2;
    // int  degra;
    // int  persp;
    // 
}   t_env

typedef struct
{
    int     x;
    int     y;
    char    **argv;
    // char    **map;
    // char    **tmp;
}   t_map;