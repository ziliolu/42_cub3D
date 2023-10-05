#include "../../includes/cub3D.h"

int	close_program(t_root *root)
{
	//add free of the structs
	(void)root;
	exit(0);
}

double ft_degrees_to_radians(double degrees)
{
    double radians;

    radians = degrees * (PI / 180);
    return (radians);
}

bool ft_err(char *str, t_root *root)
{
	if(root->error_msg)
		printf("Error: %s: %s\n", str, root->error_msg);
	else 
		printf("Error: %s\n", str);
	ft_panic(root);
	return (false);
}

char *ft_get_trimmed_line(char *line)
{
	char *tmp;
	char *tmp1;

	tmp = ft_strtrim(line, " ");
	tmp1 = ft_strtrim(tmp, "\t");
	free(tmp);
	return (tmp1);
}

bool ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}
