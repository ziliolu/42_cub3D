#include "../../includes/cub3D.h"

void ft_init_rays(t_root *root, t_player *player, int i, int flag)
{
	double res_x;
	double res_y;

	player->plane_x = 0.66;
	player->plane_y = 0;
	player->dir_x = 0;
	player->dir_y = -1;
	root->map->map_x = (int)player->x;
	root->map->map_y = (int)player->y;
	root->camera_x = 2 * i / (float)SCREEN_WIDTH - 1;
	res_x = player->plane_x * root->camera_x;
	res_y = player->plane_y * root->camera_x;
	if (flag)
	{
		res_x *= -1;
		res_y *= -1;
	}
	root->ray->ray_dir_x  = player->dir_x + res_x;
	root->ray->ray_dir_y = player->dir_y + res_y;
	root->hit_wall = 0;
}

void ft_cast_rays(t_root *root)
{
	int i;
	int flag = 1;

	i = 0;
	while(i < SCREEN_WIDTH)
	{
		if (i > SCREEN_WIDTH / 2)
			flag = 0;
		ft_init_rays(root, root->player, i, flag);
		ft_set_ray_length(root->ray);
		ft_set_step_and_side_dist(root->ray, root->player, root->map);
		ft_dda_algorithm(root, root->ray, root->map);
		ft_draw(root->ray, root->mlx, i);
		i++;
	}
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->mlx->map.img, 0, 0);
}
