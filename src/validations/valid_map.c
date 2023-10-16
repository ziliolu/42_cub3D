/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:29 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/16 14:49:00 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_create_map_arr(t_map *map)
{
	int		map_file;
	int		i;

	map_file = open(MAP, O_RDONLY);
	map->is_map_allocated = 1;
	map->map_arr = calloc(sizeof(char *), map->n_lines + 1);
	i = -1;
	while (++i < map->n_lines)
		map->map_arr[i] = calloc(sizeof(char), map->n_col + 1);
	get_map_arr(map, map_file);
	if(map_file > 0)
		close(map_file); 
}

void	ft_init_player_direction(char c, t_player *player)
{
	if (c == 'N' || c == 'S')
	{
		player->plane_y = 0;
		player->dir_x = 0;
		if (c == 'N')
			set_player_y_axis(player, FOV, -1, 90);
		else
			set_player_y_axis(player, -FOV, 1, 270);
	}
	else
	{
		player->plane_x = 0;
		player->dir_y = 0;
		if (c == 'W')
			set_player_x_axis(player, -FOV, -1, 180);
		else
			set_player_x_axis(player, FOV, 1, 0);
	}
}

bool	ft_init_player(char c, int x, int y, t_player *player)
{
	if (ft_is_player(c))
	{
		if (++player->n_players > 1)
			return (false);
		player->x = (double)x + 0.50;
		player->y = (double)y + 0.50;
		ft_init_player_direction(c, player);
	}
	return (true);
}

bool	ft_read_map_file(t_map *map)
{
	int		map_file;
	char	*line;
	int		i;

	map_file = open(MAP, O_RDONLY);
	if (map_file < 0)
		return (false);
	line = get_next_line(map_file);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (i > map->n_col)
			map->n_col = i;
		map->n_lines++;
		free(line);
		line = get_next_line(map_file);
	}
	ft_create_map_arr(map);
	close(map_file);
	return (true);
}

bool	ft_add_map_file(char *line)
{
	int	map_file;

	map_file = open(MAP, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if (map_file < 0)
		return (false);
	while (*line)
	{
		if (*line == '\t')
			write(map_file, "    ", 4);
		else
			write(map_file, line, 1);
		line++;
	}
	close(map_file);
	return (true);
}
