#include "../../includes/cub3D.h"

void is_moving(int key_code, int flag, t_moves *moves)
{
	if (key_code == W)
		moves->w_press = flag;
	if (key_code == S)
		moves->s_press = flag;
	if (key_code == A)
		moves->a_press = flag;
	if (key_code == D)
		moves->d_press = flag;
}

void is_rotating(int key_code, int flag, t_moves *moves)
{
	if (key_code == LEFT)
		moves->left_press = flag;
	if (key_code == RIGHT)
		moves->right_press = flag;
}

int	on_key_press(int key_code, t_root *root)
{
	if (key_code == ESC)
		close_program(root);
	is_moving(key_code, 1, root->moves);
	is_rotating(key_code, 1, root->moves);
	return (0);
}

int on_key_release(int key_code, t_root *root)
{
	is_moving(key_code, 0, root->moves);
	is_rotating(key_code, 0, root->moves);
	return (0);
}

void ft_movements(t_root *root, t_player *player, t_moves *moves)
{
	if (moves->w_press)
		player_movement(player, W, root);
	if (moves->s_press)
		player_movement(player, S, root);
	if (moves->a_press)
		player_movement(player, A, root);
	if (moves->d_press)
		player_movement(player, D, root);
	if (moves->left_press)
		player_rotation(player, LEFT);
	if (moves->right_press)
		player_rotation(player, RIGHT);
}