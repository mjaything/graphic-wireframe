#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

# define WIDTH              1080
# define HEIGHT             1920
# define MENU_WIDTH         300

# define COLOR_TEXT_WHITE				0xFFFFFF
# define COLOR_MENU_LIGHT_BLACK			0x121212
# define COLOR_BACKGROUND_ROSE_WHITE	0xFDF2EE
# define COLOR_WIRE_ROSE_WHITE_SHADE_1	0xCAC2BE
# define COLOR_WIRE_ROSE_WHITE_SHADE_2	0x827C7A
# define COLOR_WIRE_ROSE_WHITE_SHADE_3	0x534F4E
# define COLOR_WIRE_ROSE_WHITE_SHADE_4	0x353232
# define COLOR_WIRE_ROSE_WHITE_SHADE_5	0x222020

# define MOUSE_LEFT_CLICK				1
# define MOUSE_RIGHT_CLICK	            2
# define MOUSE_THIRD_CLICK	            3
# define MOUSE_SCROLL_UP	            4
# define MOUSE_SCROLL_DOWN	            5
# define MOUSE_SCROLL_LEFT	            6
# define MOUSE_SCROLL_RIGHT	            7

# define KEYBOARD_MAIN_PAD_0			29
# define KEYBOARD_MAIN_PAD_1			18
# define KEYBOARD_MAIN_PAD_2			19
# define KEYBOARD_MAIN_PAD_3			20
# define KEYBOARD_MAIN_PAD_4			21
# define KEYBOARD_MAIN_PAD_5			23
# define KEYBOARD_MAIN_PAD_6			22
# define KEYBOARD_MAIN_PAD_7			26
# define KEYBOARD_MAIN_PAD_8			28
# define KEYBOARD_MAIN_PAD_9			25
# define KEYBOARD_MAIN_PAD_I			34
# define KEYBOARD_MAIN_PAD_P			35
# define KEYBOARD_MAIN_PAD_ESC		    53
# define KEYBOARD_MAIN_PAD_PLUS         24
# define KEYBOARD_MAIN_PAD_MINUS		27
# define KEYBOARD_MAIN_PAD_LESS         43
# define KEYBOARD_MAIN_PAD_MORE         47

# define KEYBOARD_ARROW_LEFT            123
# define KEYBOARD_ARROW_RIGHT           124
# define KEYBOARD_ARROW_DOWN            125
# define KEYBOARD_ARROW_UP              126

# define KEYBOARD_NUM_PAD_0			    82
# define KEYBOARD_NUM_PAD_1			    83
# define KEYBOARD_NUM_PAD_2			    84
# define KEYBOARD_NUM_PAD_3			    85
# define KEYBOARD_NUM_PAD_4			    86
# define KEYBOARD_NUM_PAD_5			    87
# define KEYBOARD_NUM_PAD_6			    88
# define KEYBOARD_NUM_PAD_7			    89
# define KEYBOARD_NUM_PAD_8			    91
# define KEYBOARD_NUM_PAD_9			    92
# define KEYBOARD_NUM_PAD_PLUS		    69
# define KEYBOARD_NUM_PAD_MINUS		    78

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
    int         x;
    int         y;
    int         old_x;
    int         old_y;
    char        clicked;
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