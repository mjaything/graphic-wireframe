#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include "../minilibx_macos/mlx_int.h"
# include "../minilibx_macos/mlx_new_window.h"

# define ERR_USAGE						"Error: Invalid input arguments. Usage: ./fdf MAP_FILE"
# define ERR_MAP_FILE					"Error: Invalid map file."
# define ERR_MAP_OPENING				"Error: Map opening."
# define ERR_MAP_LOADING				"Error: Map loading."
# define ERR_MAP_INIT					"Error: Map initialization."
# define ERR_ENV_INIT_MEMALLOC			"Error: Environment initialization - memalloc."
# define ERR_ENV_INIT_MLX				"Error: Environment initialization(mlx)."
# define ERR_ENV_INIT_WIN				"Error: Environment initialization(win)."
# define ERR_ENV_INIT_IMG				"Error: Environment initialization(img)."
# define ERR_ENV_INIT_MOUSE				"Error: Environment initialization(mouse)."
# define ERR_TRANSFORM_TO_ARRAY_		"Error: Transformation from stack to array(matrix_elements)."
# define ERR_TRANSFORM_TO_ARRAY_COLOR	"Error: Transformation from stack to array(color array)."
# define ERR_CAMERA_INIT				"Error: Camera initialization."

# define WIDTH              			1080
# define HEIGHT             			1920
# define INSTRUCTION_WIDTH     			300

# define COLOR_TEXT_BLACK				0x000000
# define COLOR_INSTRUCTION_WHITE		0xFFFFFF
# define COLOR_BACKGROUND_ROSE_WHITE	0xFDF2EE
# define COLOR_WIRE_PALE_SLATE			0xCAC2BE
# define COLOR_WIRE_HURRICANE			0x827C7A
# define COLOR_WIRE_TUNDORA				0x534F4E
# define COLOR_WIRE_NIGHT_RIDER			0x353232
# define COLOR_WIRE_NERO				0x222020

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

typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	isometric,
	parallel
}	t_projection;

typedef struct
{
    int x;
    int y;
    int z;
    int color;
}   t_point;

typedef struct
{
    int 	width;
    int		height;
	int  	z_min;
    int  	z_max;
    int  	z_range;
	int  	*matrix_element_arr;
    int  	*color_arr;
}   t_map;

typedef struct
{
    t_projection projection;
    int          zoom;
    double       alpha;
    double       beta;
    double       gamma;
    float        z_divisor;
    int          x_offset;
    int          y_offset;
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
    int     			z;
    int     			color;
    t_matrix_element  	*next;
}   t_matrix_element;

typedef struct
{
    void    	*mlx_ptr;
    void    	*win_ptr;
    void    	*img_ptr;
    char    	*data_addr;
    int      	bits_per_pixel;
    int      	size_line;
    int      	endian;
	t_mouse  	*mouse;
	t_camera 	*camera;
    t_map    	*map;
}   t_env;


int	rea

#endif