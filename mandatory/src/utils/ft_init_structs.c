/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:01:46 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/13 13:51:24 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_moves(t_root *root)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	moves->w_press = 0;
	moves->s_press = 0;
	moves->a_press = 0;
	moves->d_press = 0;
	moves->left_press = 0;
	moves->right_press = 0;
	root->moves = moves;
}

void	ft_init_colors(t_tinfo *tinfo)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		tinfo->floor[i] = -1;
		tinfo->ceil[i] = -1;
	}
}

void	ft_init_textures(t_tinfo *tinfo)
{
	memset(&tinfo->north, 0, sizeof(t_data));
	memset(&tinfo->south, 0, sizeof(t_data));
	memset(&tinfo->west, 0, sizeof(t_data));
	memset(&tinfo->east, 0, sizeof(t_data));
}

void	ft_init_map(t_map *map)
{
	map->n_col = 0;
	map->n_lines = 0;
	map->is_map_allocated = 0;
}

void	ft_init_structs(t_root *root)
{
	t_tinfo		*tinfo;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	create_rays(root);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
	root->player = player;
	player->n_players = 0;
	root->error_msg = NULL;
	ft_init_colors(root->tinfo);
	ft_init_textures(root->tinfo);
	ft_init_moves(root);
	ft_init_map(root->map);
	root->is_empty_file = false;
	root->exit_success = 0;
}
