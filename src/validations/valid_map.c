/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:57:13 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/04 15:10:14 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void ft_fill_and_replace(t_map *map, int i, int *j)
{
	int index;

	index = -1;
	while (map->map_arr[i][++index])
	{
		if (map->map_arr[i][index] == ' ')
			map->map_arr[i][index] = '0';
	}

	while (*j < map->n_col)
		map->map_arr[i][(*j)++] = '-';
}

bool ft_str_is_map_type(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '0' && str[i] != ' ' \
		&& !ft_is_player(str[i]) && str[i] != '\n' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool ft_check_all_sides(t_map *map, int y, int x)
{
	if (y == 0 || y == map->n_lines - 1 || x == 0 || x == map->n_col - 1)
		return (false);
	if(map->map_arr[y - 1][x] == '-' || map->map_arr[y + 1][x] == '-' || map->map_arr[y][x - 1] == '-' || map->map_arr[y][x + 1] == '-')
		return (false);
	return (true);
}

bool ft_check_map(t_map *map, t_player *player)
{
	int i;
	int j;

	i = 0;
	while(map->map_arr[i])
	{
		j = 0;
		while(map->map_arr[i][j])
		{
			if(ft_is_player(map->map_arr[i][j]) || map->map_arr[i][j] == '0')
            {
                if (!ft_check_all_sides(map, i, j) || !ft_init_player(map->map_arr[i][j], j, i, player))
                    return (false);
            }
			j++;
		}
		i++;
	}
	return (player->n_players != 0);
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
		map->map_arr[i] = calloc(sizeof(char), map->n_col);
		i++;
	}
	line = NULL;
	i = 0;
	while((line = get_next_line(map_file)))
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
	}
	free(line);
}

void ft_init_player_direction(char c, t_player *player)
{
    if(c == 'N' || c == 'S')
    {
        player->plane_x = FOV;
        player->plane_y = 0;
        player->dir_x = 0;
        if(c == 'N')
            player->dir_y = -1;
        else
            player->dir_y = 1;
    }
    else
    {
        player->plane_x = 0;
        player->plane_y = FOV;
        player->dir_y = 0;
        if(c == 'W')
            player->dir_x = -1;
        else
            player->dir_x = 1;
    }
}

bool ft_init_player(char c, int x, int y, t_player *player)
{
	if(ft_is_player(c))
	{
		if(++player->n_players > 1)
			return (false);
		player->x = (double)x + 0.50;
		player->y = (double)y + 0.50;
		ft_init_player_direction(c, player);
	}
    return (true);
}

bool ft_read_map_file(t_map *map)
{
    int map_file;
    char *line;
    int i;

    map_file = open(MAP, O_RDONLY);
    if(!map_file)
        return (false);
    line = NULL;
    while((line = get_next_line(map_file)))
    {
        i = 0;
        while(line[i] && line[i] != '\n')
        {
            i++;
        }
        if(i > map->n_col)
            map->n_col = i;
        map->n_lines++;
    }
    close(map_file);
    ft_create_map_arr(map);
    return (true);
}

bool ft_is_valid_map(t_root *root)
{
	if(!ft_read_map_file(root->map))
        return (false);
    if(!ft_check_map(root->map, root->player))
	    return (false);

    return (true);
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