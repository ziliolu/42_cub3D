/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:45:56 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:25:05 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_ray(t_root *root, t_player *player, int i)
{
	root->map->map_x = (int)player->x;
	root->map->map_y = (int)player->y;
	root->camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
	root->rays->ray_dir_x = player->dir_x
		+ player->plane_x * root->camera_x;
	root->rays->ray_dir_y = player->dir_y + player->plane_y * root->camera_x;
	root->rays->line_height = -1;
	root->hit_wall = 0;
}

int	ft_get_pixel(t_data img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void	ft_create_map_image(t_mlx *mlx)
{
	t_data	map;

	map.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	mlx->map = map;
}

int	ft_create_argb(int transparency, int r, int g, int b)
{
	return (transparency << 24 | r << 16 | g << 8 | b);
}

int	ft_render_map(t_root *root)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		if (i < SCREEN_HEIGHT / 2)
			color = ft_create_argb(TRANSPARENCY, root->tinfo->ceil[0],
					root->tinfo->ceil[1], root->tinfo->ceil[2]);
		else
			color = ft_create_argb(TRANSPARENCY, root->tinfo->floor[0],
					root->tinfo->floor[1], root->tinfo->floor[2]);
		while (++j < SCREEN_WIDTH)
			my_mlx_pixel_put(&root->mlx->map, j, i, color);
	}
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win,
		root->mlx->map.img, 0, 0);
	ft_cast_rays(root);
	ft_render_mini_map(root->mlx, root->map, root->player, root->rays);
	ft_movements(root, root->player, root->moves);
	return (0);
}
