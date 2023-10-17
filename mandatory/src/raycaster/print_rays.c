/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:34:44 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:24:48 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_single_ray(t_ray *rays, t_mlx *mlx, double x, double y)
{
	int	pixels;

	pixels = 50;
	while (pixels)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x000000FF);
		x += rays->ray_dir_x;
		y += rays->ray_dir_y;
		--pixels;
	}
}

t_ray	*skip_rays(t_ray *rays, int n)
{
	int	i;

	i = -1;
	if (!rays->next)
		return (NULL);
	while (++i < n)
	{
		if (!rays->next)
			break ;
		rays = rays->next;
	}
	return (rays);
}

void	print_rays(t_mlx *mlx, t_ray *rays, t_player *player)
{
	int		n_rays;
	int		i;
	double	x;
	double	y;
	t_ray	*head;

	i = -1;
	head = rays;
	n_rays = ((SCREEN_WIDTH / FOV) / 100) * 2;
	x = player->x * SQUARE_SIZE;
	y = (player->y - 0.25) * SQUARE_SIZE;
	while (++i < n_rays)
	{
		if (!rays)
			break ;
		print_single_ray(rays, mlx, x, y);
		rays = skip_rays(rays, n_rays);
	}
	rays = head;
}

void	ft_init_draw_variables(t_root *root, t_ray *ray)
{
	ray->line_height = (int)SCREEN_HEIGHT / ray->per_wall_dist;
	ray->draw_start = (ray->line_height * -1) / 2 + SCREEN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		root->tinfo->wall_x = root->player->y
			+ ray->per_wall_dist * ray->ray_dir_y;
	if (ray->side == 1)
		root->tinfo->wall_x = root->player->x
			+ ray->per_wall_dist * ray->ray_dir_x;
	root->tinfo->wall_x -= floor(root->tinfo->wall_x);
	root->tinfo->tex_x = (int)(root->tinfo->wall_x * (double)(TEX_WIDTH));
	if ((ray->side == 0 && ray->ray_dir_x > 0))
		root->tinfo->tex_x = TEX_WIDTH - root->tinfo->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		root->tinfo->tex_x = TEX_WIDTH - root->tinfo->tex_x - 1;
	ray->tex_step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT
			/ 2 + ray->line_height / 2) * ray->tex_step;
}

void	ft_draw(t_ray *ray, t_root *root, int i)
{
	ft_init_draw_variables(root, ray);
	while (ray->draw_start <= ray->draw_end)
	{
		root->tinfo->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->tex_step;
		ray->color = ft_get_pixel(ray->xpm_img,
				root->tinfo->tex_x, root->tinfo->tex_y);
		my_mlx_pixel_put(&root->mlx->map, i, ray->draw_start, ray->color);
		ray->draw_start++;
	}
}
