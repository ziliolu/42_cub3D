/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:53:56 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/16 18:13:49 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_program(t_root *root)
{
	root->exit_success = 1;
	ft_panic(root);
	(void)root;
	exit(0);
}

double	ft_degrees_to_radians(double degrees)
{
	double	radians;

	radians = degrees * (PI / 180);
	return (radians);
}

bool	ft_err(char *str, t_root *root)
{
	printf("Error: \n");
	if (root->error_msg)
		printf("%s: %s\n", str, root->error_msg);
	else
		printf("%s\n", str);
	if (root->is_empty_file)
		ft_panic_is_empty_file(root);
	else
		ft_panic(root);
	return (false);
}

char	*ft_get_trimmed_line(char *line)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if (!ft_strcmp(line, "\n"))
	{
		return (ft_strdup(line));
	}
	tmp = ft_strtrim(line, "\n");
	tmp1 = ft_strtrim(tmp, " ");
	tmp2 = ft_strtrim(tmp1, "\t");
	free(tmp);
	free(tmp1);
	return (tmp2);
}

bool	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}
