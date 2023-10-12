/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:52:11 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 15:53:48 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_colision(double x_value, double y_value, t_root *root)
{
	int	x;
	int	y;

	x = (int)x_value;
	y = (int)y_value;
	if (root->map->map_arr[y][x] == '1')
		return ;
	root->player->x = x_value;
	root->player->y = y_value;
}

bool	ft_is_quadrant(int key_code, t_player *player, t_root *root)
{
	double	angle;
	double	x_value;
	double	y_value;

	angle = round(player->angle);
	if (angle == 0 || angle == 90 || angle == 180 || angle == 270)
		return (false);
	x_value = player->plane_x * SPEED;
	y_value = player->plane_y * SPEED;
	if (key_code == A)
		check_colision(player->x - x_value, player->y - y_value, root);
	if (key_code == D)
		check_colision(player->x + x_value, player->y + y_value, root);
	return (true);
}

void	player_movement(t_player *player, int key_code, t_root *root)
{
	double	angle;
	double	x_value;
	double	y_value;

	angle = round(player->angle);
	x_value = player->dir_x * SPEED;
	y_value = player->dir_y * SPEED;
	if (key_code == W)
		check_colision(player->x + x_value, player->y + y_value, root);
	else if (key_code == S)
		check_colision(player->x - x_value, player->y - y_value, root);
	else if (!ft_is_quadrant(key_code, player, root))
	{
		if ((key_code == A && angle == 0) || (key_code == D && angle == 180))
			check_colision(player->x, player->y - SPEED / 2, root);
		if ((key_code == A && angle == 90) || (key_code == D && angle == 270))
			check_colision(player->x - SPEED / 2, player->y, root);
		if ((key_code == A && angle == 180) || (key_code == D && angle == 0))
			check_colision(player->x, player->y + SPEED / 2, root);
		if ((key_code == A && angle == 270) || (key_code == D && angle == 90))
			check_colision(player->x + SPEED / 2, player->y, root);
	}
}

void	player_rotation(t_player *player, int key_code)
{
	double	old_dirx;
	double	old_planex;
	double	rotation;

	old_dirx = player->dir_x;
	old_planex = player->plane_x;
	rotation = SPEED;
	if (key_code == LEFT)
		rotation *= -1;
	player->dir_x = old_dirx * cos(rotation) - player->dir_y * sin(rotation);
	player->dir_y = old_dirx * sin(rotation) + player->dir_y * cos(rotation);
	player->plane_x = old_planex * cos(rotation) - player->plane_y
		* sin(rotation);
	player->plane_y = old_planex * sin(rotation) + player->plane_y
		* cos(rotation);
	player->angle = acos(player->dir_x) * (180 / PI);
	if (player->dir_y > 0)
		player->angle = (double)(360 - player->angle);
	if (round(player->angle) == 360)
		player->angle = 0;
}

void	hooks(t_root *root)
{
	mlx_hook(root->mlx->win, 2, 1L << 0, on_key_press, root);
	mlx_hook(root->mlx->win, 3, 1L << 1, on_key_release, root);
	mlx_hook(root->mlx->win, 17, (1L << 2), close_program, root);
	mlx_loop_hook(root->mlx->mlx, ft_render_map, root);
	mlx_loop(root->mlx->mlx);
}
