/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:57:10 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/10 18:50:21 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool ft_add_rgb(char *path, int *arr)
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
		{
			free(tmp);
			return (false);
		}
			
		arr[j] = res;
		free(tmp);
		if (path[i] && path[i+1])
			i++;
		else
			break ;
		start = i;
	}
	return (true);
}

bool ft_is_text_or_color_filled(char *id, t_tinfo *tinfo)
{
    if (!ft_strcmp(id, "F"))
        return(ft_is_color_complete(tinfo->floor));
    else if (!ft_strcmp(id, "C"))
        return(ft_is_color_complete(tinfo->ceil));
    else if (!ft_strcmp(id, "NO"))
        return(tinfo->north.img);
    else if (!ft_strcmp(id, "SO"))
        return (tinfo->south.img);
    else if (!ft_strcmp(id, "WE"))
        return (tinfo->west.img);
    else if (!ft_strcmp(id, "EA"))
        return (tinfo->east.img);
    return (false);
}

bool ft_add_paths(char *id, char *path, t_tinfo *tinfo, t_mlx *mlx)
{
	int w;
	int h;

	if(!id)
		return (false);
	
    if(ft_is_text_or_color_filled(id, tinfo))
	{
        return (false);
	}
	if(!ft_strcmp(id, "F"))
		return (ft_add_rgb(path, tinfo->floor));
	else if(!ft_strcmp(id, "C"))
		return (ft_add_rgb(path, tinfo->ceil));
	if(open(path, O_RDONLY) == -1 || !ft_is_valid_extension(path, ".xpm"))
		return (false);
	else if(!ft_strcmp(id, "NO") && !tinfo->north.img)
	{
		tinfo->north.img = mlx_xpm_file_to_image(mlx->mlx, \
	path, &w, &h);
		tinfo->north.addr = mlx_get_data_addr(tinfo->north.img, \
		&tinfo->north.bits_per_pixel, &tinfo->north.line_length, &tinfo->north.endian);
	}
	else if(!ft_strcmp(id, "SO") && !tinfo->south.img)
	{
		tinfo->south.img = mlx_xpm_file_to_image(mlx->mlx, \
	path, &w, &h);
		tinfo->south.addr = mlx_get_data_addr(tinfo->south.img, \
		&tinfo->south.bits_per_pixel, &tinfo->south.line_length, &tinfo->south.endian);
	}
	else if(!ft_strcmp(id, "WE") && !tinfo->west.img)
	{
		tinfo->west.img = mlx_xpm_file_to_image(mlx->mlx, \
	path, &w, &h);
		tinfo->west.addr = mlx_get_data_addr(tinfo->west.img, \
		&tinfo->west.bits_per_pixel, &tinfo->west.line_length, &tinfo->west.endian);
	}
	else if(!ft_strcmp(id, "EA") && !tinfo->east.img)
	{
		tinfo->east.img = mlx_xpm_file_to_image(mlx->mlx, \
	path, &w, &h);
		tinfo->east.addr = mlx_get_data_addr(tinfo->east.img, \
		&tinfo->east.bits_per_pixel, &tinfo->east.line_length, &tinfo->east.endian);
	}
	return (true);
}

bool ft_valid_identifier(char *id, char *path, t_root *root)
{
	if(!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE") \
		|| !ft_strcmp(id, "EA") || !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
	{
		return (ft_add_paths(id, path, root->tinfo, root->mlx));
	}
	return (false);
}

bool ft_verify_identifiers(char *str, t_root *root)
{
	int i;
	char *tmp;
	char *identifier;
	char *path;
    bool result;

	tmp = ft_strtrim(str, "\n");
    result = true;
	i = 0;
	while(tmp[i] && tmp[i] != ' ')
		i++;
	identifier = ft_substr(tmp, 0, i);
	while(tmp[i] && tmp[i] == ' ')
		i++;
	path = ft_substr(tmp, i, (ft_strlen(tmp) - i));
	if(!ft_valid_identifier(identifier, path, root))
        result = false;
	free(tmp);
	free(path);
    free(identifier);
    return (result);
}