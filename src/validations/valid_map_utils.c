/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:04:06 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 18:05:11 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_fill_and_replace(t_map *map, int i, int *j)
{
	int	index;

	index = -1;
	while (map->map_arr[i][++index])
	{
		if (map->map_arr[i][index] == ' ')
			map->map_arr[i][index] = '0';
	}
	while (*j < map->n_col)
		map->map_arr[i][(*j)++] = '-';
}

bool	ft_str_is_map_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' '
			&& !ft_is_player(str[i]) && str[i] != '\n' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_all_sides(t_map *map, int y, int x)
{
	if (y == 0 || y == map->n_lines - 1 || x == 0 || x == map->n_col - 1)
		return (false);
	if (map->map_arr[y - 1][x] == '-' || map->map_arr[y + 1][x] == '-'
		|| map->map_arr[y][x - 1] == '-' || map->map_arr[y][x + 1] == '-')
		return (false);
	return (true);
}

bool	ft_is_valid_map(t_root *root)
{
	if (!ft_read_map_file(root->map))
		return (false);
	if (!ft_check_map(root->map, root->player))
		return (false);
	return (true);
}

bool	ft_check_map(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_arr[i])
	{
		j = 0;
		while (map->map_arr[i][j])
		{
			if (ft_is_player(map->map_arr[i][j]) || map->map_arr[i][j] == '0')
			{
				if (!ft_check_all_sides(map, i, j)
					|| !ft_init_player(map->map_arr[i][j], j, i, player))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (player->n_players != 0);
}
