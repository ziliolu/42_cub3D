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

# define MAP "map_file"

typedef struct s_tinfo
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
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

typedef struct s_root
{
	t_tinfo *tinfo;
	t_map	*map;
}				t_root;

void ft_print_textures(t_tinfo *tinfo);
int ft_panic(t_root *root);

#endif