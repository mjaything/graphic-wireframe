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
# define ERR_TRANSFORM_TO_ARRAY			"Error: Transformation from stack to array(matrix_elements)."
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

# define MOUSE_LEFT_BUTTON				1
# define MOUSE_RIGHT_BUTTON	            2
# define MOUSE_THIRD_BUTTON	            3
# define MOUSE_SCROLL_UP	            4
# define MOUSE_SCROLL_DOWN	            5
# define MOUSE_SCROLL_LEFT	            6
# define MOUSE_SCROLL_RIGHT	            7

# define KEYBOARD_MAIN_0			29
# define KEYBOARD_MAIN_1			18
# define KEYBOARD_MAIN_2			19
# define KEYBOARD_MAIN_3			20
# define KEYBOARD_MAIN_4			21
# define KEYBOARD_MAIN_5			23
# define KEYBOARD_MAIN_6			22
# define KEYBOARD_MAIN_7			26
# define KEYBOARD_MAIN_8			28
# define KEYBOARD_MAIN_9			25
# define KEYBOARD_MAIN_I			34
# define KEYBOARD_MAIN_P			35
# define KEYBOARD_MAIN_ESC		    53
# define KEYBOARD_MAIN_PLUS         24
# define KEYBOARD_MAIN_MINUS		27
# define KEYBOARD_MAIN_LESS         43
# define KEYBOARD_MAIN_MORE         47

# define KEYBOARD_ARROW_LEFT            123
# define KEYBOARD_ARROW_RIGHT           124
# define KEYBOARD_ARROW_DOWN            125
# define KEYBOARD_ARROW_UP              126

# define KEYBOARD_NUM_0			    82
# define KEYBOARD_NUM_1			    83
# define KEYBOARD_NUM_2			    84
# define KEYBOARD_NUM_3			    85
# define KEYBOARD_NUM_4			    86
# define KEYBOARD_NUM_5			    87
# define KEYBOARD_NUM_6			    88
# define KEYBOARD_NUM_7			    89
# define KEYBOARD_NUM_8			    91
# define KEYBOARD_NUM_9			    92
# define KEYBOARD_NUM_PLUS		    69
# define KEYBOARD_NUM_MINUS		    78

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

void	    			switch_camera_projection(int key, t_env *env);
void	    			move_camera(int key, t_env *env);
void					zoom_camera(int key, t_env *env);
void					rotate_camera(int key, t_env *env);
void					flatten_camera(int key, t_env *env);
static int				is_digit_base(char c, int base);
static t_bool 			has_prefix(const char *str, int base);
int 					is_space(int c);
t_bool 					is_number(char *str, int base);
double  				get_altitude_percentage(int start, int end, int current);
int 					get_basic_color(int z, t_map *map);
int 					get_light(int start, int end, double altitude_percentage);
int 					get_final_color(t_point current, t_point start, t_point end, t_point delta);
static void 			put_pixel(t_env *env, int x, int y, int color);
static void 			draw_line(t_point a, t_point b, t_env *env);
static void 			draw_background_color(t_env *env);
void					draw_instruction(t_env *env);
void					draw(t_map *map, t_env *env);
int 					close(void *param);
void    				setup_events(t_env *env);
t_env   				*inititalize_env(t_map *map);
t_map   				*initialize_map(void);
t_camera				*initialize_camera(t_env *env);
int 					press_key(int key, void *param);
static void				free_arr(char **arr);
static t_matrix_element *new_matrix_element(char *str);
static void             parse_row(char **row_arr, t_matrix_element **matrix_element_stack, t_map *map);
int                     load_map(const int fd, t_matrix_element **matrix_element_stack, t_map *map);
int 					click_mouse(int mouse_button, int x, int y, void *param);
int 					release_mouse(int mouse_button, int x, int y, void *param);
int 					move_mouse(int x, int y, void *param);
static void 			rotate_x_axis(int *y, int *z, double alpha);
static void 			rotate_y_axis(int *x, int *z, double beta);
static void 			rotate_z_axis(int *x, int *y, double gamma);
static void 			transform_to_isometric_projection(int *x, int *y, int z);
t_point 				project_2d(t_point p, t_env *env);
void					push(t_matrix_element **matrix_elements_stack, t_matrix_element *new_element);
t_matrix_element		*pop(t_matrix_element **matrix_elements_stack);
void					transform_stack_to_array(t_matrix_element **matrix_element_stack, t_map *map);
int     				atoi_base(const char *str, int base);
int 					get_index(int x, int y, int width);
t_point 				new_point(int x, int y, t_map *map);
void					terminate(char *str);

#endif