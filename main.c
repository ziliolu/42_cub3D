#include "./includes/cub3D.h"

bool ft_is_valid_extension(char *str, char *extension)
{
    int	ext_len;
	int	str_len;
	int	i;

	ext_len = ft_strlen(extension);
	str_len = ft_strlen(str);
	i = 0;
	while (i++ < str_len - ext_len)
		str++;
	if (ft_strncmp(str, extension, ext_len) == 0)
		return (true);
	return (false);
}
bool ft_add_rgb(char *path, int colors[3])
{
	int i;
	int j;
	int start;
	int res;
	char *tmp;

	i = 0;
	start = 0;
	j = -1;
	while (++j < 3)
	{
		while (path[i] != ',' && path[i+1])
			i++;
		tmp = ft_substr(path, start, i - start);
		res = ft_atoi(tmp);
		if (res < 0 || res > 255)
			return (false);
		colors[j] = res;
		free(tmp);
		if (path[i+1])
			i++;
		else
			break ;
		start = i;
	}
	return (true);
}

bool ft_add_paths(char *id, char *path, t_tinfo *tinfo)
{
	
	if(!ft_strcmp(id, "F"))
		return (ft_add_rgb(path, tinfo->floor));
	else if(!ft_strcmp(id, "C"))
		return (ft_add_rgb(path, tinfo->ceil));
	if(open(path, O_RDONLY) == -1 || !ft_is_valid_extension(path, ".xpm"))
		return (false); 
	else if(!ft_strcmp(id, "NO") && !tinfo->north)
		tinfo->north = path;
	else if(!ft_strcmp(id, "SO") && !tinfo->south)
		tinfo->south = path;
	else if(!ft_strcmp(id, "WE") && !tinfo->west)
		tinfo->west = path;
	else if(!ft_strcmp(id, "EA") && !tinfo->east)
		tinfo->east = path;
	return (true);
}
bool ft_valid_identifier(char *id, char *path, t_tinfo *tinfo)
{
	if(!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE") \
		|| !ft_strcmp(id, "EA") || !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
		return (ft_add_paths(id, path, tinfo));
	return (false);
}
bool ft_verify_identifiers(char *str, t_tinfo *tinfo)
{
	int i; 
	char *tmp;
	char *identifier;
	char *path;

	tmp = ft_strtrim(str, " ");
	i = 0;

	while(tmp[i] && tmp[i] != ' ')
		i++;
	identifier = ft_substr(tmp, 0, i);
	while(tmp[i] && tmp[i] == ' ')
		i++;
	path = ft_substr(tmp, i, ft_strlen(tmp) - i - 1);
	if(!ft_valid_identifier(identifier, path, tinfo))
		return (false);

	free(tmp);
	return (true);
}

bool ft_err(char *str, t_root *root)
{
	printf("Error: %s\n", str);
	ft_panic(root);
	return (false);
}

char *get_trimmed_line(char *line)
{
	char *tmp;
	char *tmp1;

	tmp = ft_strtrim(line, " ");
	tmp1 = ft_strtrim(tmp, "\t");
	free(tmp);
	return (tmp1);
}

bool ft__istinfo_complete(t_tinfo *tinfo)
{
	//falta verificar floor e ceiling
	if(tinfo->north && tinfo->south && tinfo->west && tinfo->east) 
		return (true);
	return (false);
}

bool ft_add_map_file(char *line)
{
	int map_file;
	map_file = open(MAP, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if(!map_file)
		return (false);
	while(*line)
	{
		if(*line == '\t')
			write(map_file, "    ", 4);
		else
			write(map_file, line, 1);
		line++;	
	}
	close(map_file);
	return (true);
}
bool ft_str_is_map_type(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '0' && str[i] != ' ' \
		&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != '\n' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}
bool ft_is_valid_file(char *str, t_tinfo *tinfo)
{
	int fd;
	char *line;
	char *tmp;
	int copy_map;

	fd = open(str, O_RDONLY);
	copy_map = 0;
	if(open(MAP, O_RDWR) != -1)
		open(MAP, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if(fd == -1)
		return (false);
	line = NULL;
	while((line = get_next_line(fd)))
	{
		tmp = get_trimmed_line(line);
		if((ft_isdigit(tmp[0]) || tmp[0] == ' ' ) && ft_str_is_map_type(line))
		{
			if(!ft__istinfo_complete(tinfo))
			{
				free(tmp);
				free(line);
				return (false);
			}
			copy_map = 1;
			ft_add_map_file(line);
		}
		else if(copy_map == 1 || (ft_strcmp(tmp, "\n") && !ft_verify_identifiers(tmp, tinfo)))
		{
			free(line);
			free(tmp);
			return (false);
		}
		free(tmp);
		free(line);
	}
	ft_print_textures(tinfo);
	close (fd);
	free(line);
	return (true);
}

void ft_create_map_arr(t_map *map)
{
	int map_file;
	char *line;
	int i;
	int j;

	map_file = open(MAP, O_RDONLY);
	map->map_arr = calloc(sizeof(char *), map->n_lines + 1);
	i = 0;
	while(i < map->n_lines)
	{
		map->map_arr[i] = malloc(map->n_col * sizeof(char));
		i++;
	}
	line = NULL;
	i = 0;
	while((line = get_next_line(map_file)))
	{
		j = 0;
		while(j < map->n_col)
		{
			if (line[j] && line[j] != ' ' && line[j] != '\n') 
				map->map_arr[i][j] = line[j];
			else
				map->map_arr[i][j] = '-';
			j++;
		}
		map->map_arr[i][j] = '\0';
		free(line);
		i++;
	}
	free(line);
	ft_print_arr(map->map_arr);
}

// ft_is_closed_map(char **map)
// {

// }

bool ft_is_valid_map(t_map *map)
{
	int player;
	int map_file;
	char *line;
	int i;

	player = 0;
	map_file = open(MAP, O_RDONLY);
	if(!map_file)
		return (false);
	line = NULL;
	while((line = get_next_line(map_file)))
	{
		i = 0;
		while(line[i] && line[i] != '\n')
		{
			if(line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W')
			{
				map->player_pos[0] = map->n_col;
				map->player_pos[1] = map->n_lines;
				player++;
			}
			i++;
		}
		if(i > map->n_col)
			map->n_col = i;
		map->n_lines++;
	}
	close(map_file);
	printf("players: %d\n", player);
	printf("lines: %d\n", map->n_lines);
	printf("cols: %d\n", map->n_col);
	ft_create_map_arr(map);
	// return (player == 1 || ft_is_closed_map(root->map->map_arr));
	return (player == 1);
}


//todas as chamadas para error sao dadas aqui, assim evitamos double frees
bool ft_initial_validation(char *str, t_root *root)
{
	if (!ft_is_valid_extension(str, ".cub"))
		return ft_err("invalid extension", root);
	if (!ft_is_valid_file(str, root->tinfo))
		return ft_err("invalid file", root);
	if(!ft_is_valid_map(root->map))
		return(ft_err("invalid map", root));
	return (true);
}

void ft_init_structs(t_root *root)
{
	t_tinfo *tinfo;
	t_map *map;
	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));

	tinfo->north = NULL;
	tinfo->south = NULL;
	tinfo->east = NULL;
	tinfo->west = NULL;

	root->tinfo = tinfo;
	root->map = map;
}

int main(int argc, char **argv)
{

	t_root *root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	if (argc != 2)
		return (ft_panic(root));
	if(!ft_initial_validation(argv[1], root))
		return (1);
}
