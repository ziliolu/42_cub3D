/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:57:10 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/09/26 16:06:16 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

bool ft_add_paths(char *id, char *path, t_root *root)
{
	int w;
	int h;
	if(!ft_strcmp(id, "F"))
		return (ft_add_rgb(path, root->tinfo->floor));
	else if(!ft_strcmp(id, "C"))
		return (ft_add_rgb(path, root->tinfo->ceil));
	if(open(path, O_RDONLY) == -1 || !ft_is_valid_extension(path, ".xpm"))
		return (false); 
	else if(!ft_strcmp(id, "NO") && !root->tinfo->north)
	{
		root->tinfo->north = mlx_xpm_file_to_image(root->mlx->mlx, \
		path, &w, &h);
	}
	else if(!ft_strcmp(id, "SO") && !root->tinfo->south)
	{
		root->tinfo->south = mlx_xpm_file_to_image(root->mlx->mlx, \
	path, &w, &h);
	}
	else if(!ft_strcmp(id, "WE") && !root->tinfo->west)
	{
		root->tinfo->west = mlx_xpm_file_to_image(root->mlx->mlx, \
	path, &w, &h);
	}
	else if(!ft_strcmp(id, "EA") && !root->tinfo->east)
	{
		root->tinfo->east = mlx_xpm_file_to_image(root->mlx->mlx, \
	path, &w, &h);
	}
	return (true);
}

bool ft_valid_identifier(char *id, char *path, t_root *root)
{
	if(!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE") \
		|| !ft_strcmp(id, "EA") || !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
	{
		return (ft_add_paths(id, path, root));
	}
	return (false);
}

bool ft_verify_identifiers(char *str, t_root *root)
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
	if(!ft_valid_identifier(identifier, path, root))
		return (false);

	free(tmp);
	return (true);
}