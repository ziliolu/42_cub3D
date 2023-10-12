/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:38:47 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:32:33 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//length of ray from one x or y-side to next x or y-side
void	ft_set_ray_length(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dis_x = MAX;
	else
		ray->delta_dis_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dis_y = MAX;
	else
		ray->delta_dis_y = fabs(1 / ray->ray_dir_y);
}

void	ft_set_step_and_side_dist(t_ray *ray, t_player *player, t_map *map)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - map->map_x) * ray->delta_dis_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map->map_x + 1.0 - player->x) * ray->delta_dis_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - map->map_y) * ray->delta_dis_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map->map_y + 1.0 - player->y) * ray->delta_dis_y;
	}
}

void	until_hits_wall(t_root *root, t_ray *ray, t_map *map)
{
	while (root->hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dis_x;
			map->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dis_y;
			map->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map_arr[map->map_y][map->map_x] == '1')
			root->hit_wall = 1;
	}
}

void	ft_dda_algorithm(t_root *root, t_ray *ray, t_map *map)
{
	until_hits_wall(root, ray, map);
	if (ray->side == 0)
	{
		if (map->map_x - root->player->x < 0)
			ray->xpm_img = root->tinfo->west;
		else
			ray->xpm_img = root->tinfo->east;
		ray->per_wall_dist = ray->side_dist_x - ray->delta_dis_x;
	}
	else
	{
		if (map->map_y - root->player->y < 0)
			ray->xpm_img = root->tinfo->north;
		else
			ray->xpm_img = root->tinfo->south;
		ray->per_wall_dist = ray->side_dist_y - ray->delta_dis_y;
	}
}
