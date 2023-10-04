#include "../../includes/cub3D.h"

void check_colision(double x_value, double y_value, t_root *root)
{
	int x;
	int y;

	x = (int)x_value;
	y = (int)y_value;
	if (root->map->map_arr[y][x] == '1')
		return ;
	root->player->x = x_value;
	root->player->y = y_value;
}

void	player_movement(t_player *player,  int key_code, t_root *root)
{
	double x_value;
	double y_value;

	x_value = player->dir_x * SPEED;
	y_value = player->dir_y * SPEED;
	if (key_code == W)
		check_colision(player->x + x_value, player->y + y_value, root);
	if (key_code == S)
		check_colision(player->x - x_value, player->y - y_value, root);
	if (key_code == A)
	{
		check_colision(player->x - y_value, player->y - x_value, root);
		/* if (y_value <= 0) */
		/* else
			check_colision(player->x + y_value, player->y + x_value, root); */
	}
	if (key_code == D)
	{
		check_colision(player->x + y_value, player->y + x_value, root);
		/* if (y_value <= 0) */
		/* else
			check_colision(player->x - y_value, player->y - x_value, root); */
	}
	ft_render_map(root);
}

void player_rotation(t_player *player, int key_code, t_root *root)
{
	double oldDirX;
	double oldPlaneX;
	double rotation;

	oldDirX = player->dir_x;
	oldPlaneX = player->plane_x;
	rotation = ROTATION;
	if (key_code == LEFT)
		rotation *= -1;
	player->dir_x = oldDirX * cos(rotation) - player->dir_y * sin(rotation);
	player->dir_y = oldDirX * sin(rotation) + player->dir_y * cos(rotation);
	player->plane_x = oldPlaneX * cos(rotation) - player->plane_y * sin(rotation);
	player->plane_y = oldPlaneX * sin(rotation) + player->plane_y * cos(rotation);
	ft_render_map(root);
}

int	on_key_press(int key_code, t_root *root)
{
	if (key_code == ESC)
		exit(0);
	if (is_moving(key_code))
		player_movement(root->player, key_code, root);
	if (is_rotating(key_code))
		player_rotation(root->player, key_code, root);
	return (0);
}

int	close_program(void)
{
	//add free of the structs
	exit(0);
}

void	hooks(t_root *root)
{
	mlx_hook(root->mlx->win, 2, 1, on_key_press, root);
	mlx_hook(root->mlx->win, 17, (1L << 2), close_program, root);
	mlx_loop(root->mlx->mlx);
}