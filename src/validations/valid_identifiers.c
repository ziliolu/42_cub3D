/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:16 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 17:47:03 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	ft_add_rgb(char *path, int *arr)
{
	int		i;
	int		j;
	int		start;
	int		res;
	char	*tmp;

	i = 0;
	start = 0;
	j = -1;
	while (++j < 3)
	{
		while (path[i] != ',' && path[i + 1])
			i++;
		tmp = ft_substr(path, start, i - start);
		res = ft_atoi(tmp);
		free(tmp);
		if (res < 0 || res > 255)
			return (false);
		arr[j] = res;
		if (!path[i] || !path[i + 1])
			break ;
		i++;
		start = i;
	}
	return (true);
}

void	add_path_to_image(t_data *direction, t_mlx *mlx, char *path)
{
	int	w;
	int	h;

	direction->img = mlx_xpm_file_to_image(mlx->mlx, path, &w, &h);
	direction->addr = mlx_get_data_addr(direction->img,
			&direction->bits_per_pixel, &direction->line_length,
			&direction->endian);
}

bool	ft_add_paths(char *id, char *path, t_tinfo *tinfo, t_mlx *mlx)
{
	if (!id)
		return (false);
	if (ft_is_text_or_color_filled(id, tinfo))
		return (false);
	if (!ft_strcmp(id, "F"))
		return (ft_add_rgb(path, tinfo->floor));
	else if (!ft_strcmp(id, "C"))
		return (ft_add_rgb(path, tinfo->ceil));
	if (open(path, O_RDONLY) == -1 || !ft_is_valid_extension(path, ".xpm"))
		return (false);
	else if (!ft_strcmp(id, "NO") && !tinfo->north.img)
		add_path_to_image(&tinfo->north, mlx, path);
	else if (!ft_strcmp(id, "SO") && !tinfo->south.img)
		add_path_to_image(&tinfo->south, mlx, path);
	else if (!ft_strcmp(id, "WE") && !tinfo->west.img)
		add_path_to_image(&tinfo->west, mlx, path);
	else if (!ft_strcmp(id, "EA") && !tinfo->east.img)
		add_path_to_image(&tinfo->east, mlx, path);
	return (true);
}

bool	ft_verify_identifiers(char *str, t_root *root)
{
	int		i;
	char	*tmp;
	char	*identifier;
	char	*path;
	bool	result;

	tmp = ft_strtrim(str, "\n");
	result = true;
	i = 0;
	while (tmp[i] && tmp[i] != ' ')
		i++;
	identifier = ft_substr(tmp, 0, i);
	while (tmp[i] && tmp[i] == ' ')
		i++;
	path = ft_substr(tmp, i, (ft_strlen(tmp) - i));
	if (!ft_valid_identifier(identifier, path, root))
		result = false;
	free(tmp);
	free(path);
	free(identifier);
	return (result);
}
