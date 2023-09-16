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

# define MAP "map_file"

typedef struct s_tinfo
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		floor[3];
	int		ceil[3];
}				t_tinfo;

typedef struct s_map
{
	char **map_arr;
	int n_col;
	int n_lines;
	int player_pos[2];
}				t_map;

typedef struct s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct s_root
{
	t_tinfo *tinfo;
	t_map	*map;
	t_mlx	*mlx;
}				t_root;


void ft_print_textures(t_tinfo *tinfo);
int ft_panic(t_root *root);
void ft_print_arr(char **arr);
void ft_print_info(t_root *root);
bool ft_add_rgb(char *path, int colors[3]);
bool ft_is_valid_extension(char *str, char *extension);
bool ft_err(char *str, t_root *root);
bool ft_is_valid_file(char *str, t_tinfo *tinfo);
bool ft_is_valid_map(t_map *map);
char *ft_get_trimmed_line(char *line);
bool ft_str_is_map_type(char *str);
bool ft__istinfo_complete(t_tinfo *tinfo);
bool ft_initial_validation(char *str, t_root *root);
bool ft_verify_identifiers(char *str, t_root *root);
bool ft_add_map_file(char *line);
#endif