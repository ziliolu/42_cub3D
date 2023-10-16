/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:31:17 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/16 17:19:45 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_panic_is_empty_file(t_root *root)
{
	free(root->tinfo);
	free(root->player);
	ft_free_minimap_imgs(root);
	if (root->mlx->mlx)
		mlx_destroy_image(root->mlx->mlx, root->mlx->map.img);
	if (root->mlx->win)
		mlx_destroy_window(root->mlx->mlx, root->mlx->win);
	if (root->mlx->mlx)
	{
		mlx_destroy_display(root->mlx->mlx);
		free(root->mlx->mlx);
	}
	free(root->map);
	free(root->mlx);
	free(root->moves);
	ft_free_rays(root->rays);
	free(root);
}

int	ft_panic(t_root *root)
{
	free(root->player);
	ft_free_rays(root->rays);
	ft_free_minimap_imgs(root);
	ft_free_mlx(root);
	free(root->tinfo);
	if (root->map->is_map_allocated)
		ft_free_double_arr(root->map->map_arr);
	free(root->mlx);
	free(root->map);
	free(root->moves);
	free(root);
	unlink(MAP);
	return (0);
}
