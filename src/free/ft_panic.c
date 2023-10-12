/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:31:17 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 15:33:43 by riolivei         ###   ########.fr       */
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
		mlx_destroy_image(root->mlx->mlx, root->tinfo->west.img);
	if (root->tinfo->west.img)
		mlx_destroy_image(root->mlx->mlx, root->tinfo->east.img);
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

int	ft_panic(t_root *root)
{
	free(root->player);
	if (root->is_empty_file == true)
		return (1);
	ft_free_rays(root->rays);
	ft_free_minimap_imgs(root);
	ft_free_mlx(root);
	free(root->tinfo);
	if (root->exit_success)
	{
		if (root->map->map_arr)
			ft_free_double_arr(root->map->map_arr);
	}
	free(root->mlx);
	free(root->map);
	free(root->moves);
	free(root);
	return (0);
}
