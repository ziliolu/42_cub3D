/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:04:06 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 18:30:57 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_player_y_axis(t_player *player, double plane_x,
	double dir_y, double angle)
{
	player->plane_x = plane_x;
	player->dir_y = dir_y;
	player->angle = angle;
}

void	set_player_x_axis(t_player *player, double plane_y,
	double dir_x, double angle)
{
	player->plane_y = plane_y;
	player->dir_x = dir_x;
	player->angle = angle;
}

void	get_map_arr(t_map *map, int map_file)
{
	int		i;
	int		j;
	char	*line;

	line = get_next_line(map_file);
	i = 0;
	while (line)
	{
		j = 0;
		while (line[j] && line[j] != '\n')
		{
			map->map_arr[i][j] = line[j];
			j++;
		}
		ft_fill_and_replace(map, i, &j);
		map->map_arr[i][j] = '\0';
		free(line);
		i++;
		line = get_next_line(map_file);
	}
	free(line);
}
