/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:09:49 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/16 17:19:38 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_rays(t_ray *rays)
{
	t_ray	*tmp;

	while (rays != NULL)
	{
		tmp = rays->next;
		free(rays);
		rays = tmp;
	}
	free(rays);
}

void	ft_free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_mlx(t_root *root)
{
	(void)root;
	mlx_destroy_image(root->mlx->mlx, root->mlx->map.img);
	if (root->tinfo->north.img)
		mlx_destroy_image(root->mlx->mlx, root->tinfo->north.img);
	if (root->tinfo->south.img)
		mlx_destroy_image(root->mlx->mlx, root->tinfo->south.img);
	if (root->tinfo->east.img)
		mlx_destroy_image(root->mlx->mlx, root->tinfo->east.img);
	if (root->tinfo->west.img)
		mlx_destroy_image(root->mlx->mlx, root->tinfo->west.img);
	if (root->mlx->win)
		mlx_destroy_window(root->mlx->mlx, root->mlx->win);
	if (root->mlx->mlx)
	{
		mlx_destroy_display(root->mlx->mlx);
		free(root->mlx->mlx);
	}
}

void	ft_free_minimap_imgs(t_root *root)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (root->map->imgs[i].img)
			mlx_destroy_image(root->mlx->mlx, root->map->imgs[i].img);
		i++;
	}
}
