#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos.h"
# include "../libft/libft.h"

# define WIDTH
# define HEIGHT

# define MOUSE_LEFT_CLICK   1
# define MOUSE_RIGHT_CLICK  2

# define KEYBOARD_ARROW_LEFT     123
# define KEYBOARD_ARROW_RIGHT    124
# define KEYBOARD_ARROW_DOWN     125
# define KEYBOARD_ARROW_UP       126
# define KEYBOARD_ESC               53
# define KEYBOARD_I                 34
# define KEYBOARD_P                 35


# define COLOR_BACKGROUND   0x222222
# define COLOR_TEXT         0xEAEAEA

enum bool { BOOL_FALSE, BOOL_TRUE };
enum projection { PROJECTION_ISOMETRIC, PROJECTION_PARALLEL };

typedef struct
{
    int x;
    int y;
    int z;
    int color;
}   t_point;

typedef struct
{
    int width;
    int height;
    // int  *coords_arr;
    // int  *colors_arr;
    // int  z_min;
    // int  z_max; 
    // int  z_range;
}   t_map;

typedef struct
{
    enum projection projection;
    int             zoom;
    // double       alpha;
    // double       beta;
    // double       gamma;
    // float        z_divisor;
    // int          x_offset;
    // int          y_offset;
}   t_camera;

typedef struct
{
    // char    click;
    int         x;
    int         y;
    int         old_x;
    int         old_y;
}   t_mouse;

typedef struct
{
    // int     z;
    // int      color;
    // t_coord_val  *next;
}   t_coord_val;


typedef struct
{
    void    *mlx;
    void    *win;
    void    *img;
    // char     *data_addr;
    // int      bits_per_pixel;
    // int      size_line;
    // int      endian;
    // t_camera *camera;
    // t_map    *map;
    // t_mouse  *mouse;
}   t_env;

#endif