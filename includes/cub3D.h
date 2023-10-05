#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h> 
# include <stdint.h>

# define FOV 0.60
# define SPEED 0.1
# define ROTATION 0.05
# define FLOOR_COLOR 0x00808080
# define CEILING_COLOR 0x005A5A5A
# define W_COLOR 0x00FF00A9
# define E_COLOR 0x000074D9
# define N_COLOR 0x00D2FF4B
# define S_COLOR 0x00FF5733
# define MAX 1e30
# define PI 3.14159265359
# define MAP "map_file"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define SQUARE_SIZE 16

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define INCOMPLETE_TEX_OR_COLOR_ERR "incomplete color or texture area"
# define INVALID_TEX_OR_COLOR_ERR "invalid texture or color"

typedef struct s_data 
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_data;

typedef struct s_tinfo
{
	t_data north;
	t_data south;
	t_data west;
	t_data east;
	int		floor[3];
	int		ceil[3];
	double wallX;
	int texX;
	int texY;
}				t_tinfo;

typedef struct s_player
{
	double x;
	double y;
	double plane_x;
	double plane_y;
	double dir_x;
	double dir_y;
	double angle;
    int n_players;
}				t_player;

typedef struct s_ray
{
	double ray_dir_x;
	double ray_dir_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dis_x;
	double delta_dis_y;
	int step_x;
	int step_y;
	double per_wall_dist;
	int color;
	int side;
    int line_height;
    int draw_start;
    int draw_end;
    double tex_step;
    double tex_pos;
	t_data xpm_img;
	struct s_ray *next;
	
}				t_ray;

typedef struct s_map
{
	char **map_arr;
	int n_col;
	int n_lines;
	t_data imgs[3];
	int		map_x;
	int		map_y;
}				t_map;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	t_data floor;
	t_data wall;
	t_data map;
	t_data mini_map;
}				t_mlx;

typedef struct s_root
{
	double		wall_num;
	double		camera_x;
    int         hit_wall;
	char 		*error_msg;
	t_tinfo 	*tinfo;
    t_ray		*rays;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
}				t_root;


void ft_print_textures(t_tinfo *tinfo);
int ft_panic(t_root *root);
void ft_print_arr(char **arr);
void ft_print_info(t_root *root);
bool ft_add_rgb(char *path, int *arr);
bool ft_is_valid_extension(char *str, char *extension);
bool ft_err(char *str, t_root *root);
bool ft_is_valid_file(char *str, t_root *root);
bool ft_is_valid_map(t_root *root);
char *ft_get_trimmed_line(char *line);
bool ft_str_is_map_type(char *str);
bool ft_istinfo_complete(t_tinfo *tinfo);
bool ft_initial_validation(char *str, t_root *root);
bool ft_verify_identifiers(char *str, t_root *root);
bool ft_add_map_file(char *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ft_render_mini_map(t_mlx *mlx, t_map *map, t_player *player, t_ray *rays);
t_data ft_create_square_img(t_mlx *mlx, int color, int size);
void ft_create_map_images(t_mlx *mlx, t_map *map);
void ft_render_map(t_root *root);
void ft_cast_rays(t_root *root);
void ft_dda_algorithm(t_root *root, t_ray *ray, t_map *map);
void ft_set_step_and_side_dist(t_ray *ray, t_player *player, t_map *map);
void ft_set_ray_length(t_ray *ray);
void ft_draw(t_ray *ray, t_root *root, int i);
bool ft_is_player(char c);
bool ft_init_player(char c, int x, int y, t_player *player);
void hooks(t_root *root);
bool is_moving(int key_code);
bool is_rotating(int key_code);
void print_rays(t_mlx *mlx, t_ray *rays, t_player *player);
void create_rays(t_root *root);
bool ft_is_closed_map_and_there_is_player(t_map *map, t_player *player);
bool ft_is_color_complete(int *color);
#endif