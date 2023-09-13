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
	if(!ft_strcmp(id, "NO") && !tinfo->north)
		tinfo->north = path;
	else if(!ft_strcmp(id, "SO") && !tinfo->south)
		tinfo->south = path;
	else if(!ft_strcmp(id, "WE") && !tinfo->west)
		tinfo->west = path;
	else if(!ft_strcmp(id, "EA") && !tinfo->east)
		tinfo->east = path;
	else if(!ft_strcmp(id, "F"))
		return (ft_add_rgb(path, tinfo->floor));
	else if(!ft_strcmp(id, "C"))
		return (ft_add_rgb(path, tinfo->ceil));
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

bool err(char *str)
{
	printf("Error: %s\n", str);
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

bool ft_is_valid_file(char *str, t_tinfo *tinfo)
{
	int fd;
	/* int map_file; */
	char *line;
	char *tmp;

	fd = open(str, O_RDONLY);
	/* map_file = open(MAP, O_CREAT | O_RDWR | O_APPEND); */
	if(fd == -1)
		return (false);
	while((line = get_next_line(fd)))
	{
		tmp = get_trimmed_line(line);
		if (ft_isdigit(tmp[0]))
		{
			free(tmp);
			break;
		}
		if(ft_strcmp(line, "\n") && !ft_verify_identifiers(line, tinfo))
		{
			free(line);
			return (err("invalid identifier"));
		}
		free(line);
	}
	printf("NO: %s\n", tinfo->north);
	printf("SO: %s\n", tinfo->south);
	printf("WE: %s\n", tinfo->west);
	printf("EA: %s\n", tinfo->east);
	printf("FLOOR 0: %d\n", tinfo->floor[0]);
	printf("FLOOR 1: %d\n", tinfo->floor[1]);
	printf("FLOOR 2: %d\n", tinfo->floor[2]);
	printf("CEIL 0: %d\n", tinfo->ceil[0]);
	printf("CEIL 1: %d\n", tinfo->ceil[1]);
	printf("CEIL 2: %d\n", tinfo->ceil[2]);
	close (fd);
	return (true);
}

bool ft_initial_validation(char *str, t_tinfo *tinfo)
{
	if (!ft_is_valid_extension(str, ".cub"))
		return err("invalid extension");
	if (!ft_is_valid_file(str, tinfo))
		return err("invalid file");
	return (true);
}

int main(int argc, char **argv)
{

	t_tinfo *tinfo;

	tinfo = malloc(sizeof(t_tinfo));

	tinfo->north = NULL;
	tinfo->south = NULL;
	tinfo->east = NULL;
	tinfo->west = NULL;
	if (argc != 2)
		return (1);
	if(!ft_initial_validation(argv[1], tinfo))
		return (1);
}
