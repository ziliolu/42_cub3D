#include "../../includes/cub3D.h"

double ft_degrees_to_radians(double degrees)
{
	double radians;

	radians = degrees * (PI / 180);
	return (radians);
}

//calculate ray position and direction
void ft_init_rays(t_root *root, t_player *player)
{
	root->map->map_x = int(player->x);
	root->map->map_y = int(player->y);
	root->camera_x = 2 * game->wall_n / SCREEN_WIDTH - 1;
	root->ray->ray_dir_x = player->dir_x + player->plane_x * root->camera_x;
	root->ray->ray_dir_x = player->dir_y + player->plane_y * root->camera_x;

}

//length of ray from one x or y-side to next x or y-side
void ft_set_ray_length(t_ray *ray)
{
	if(ray->ray_dir_x == 0)
		ray->delta_dist_x = MAX;
	else 
		ray->delta_dist_x = abs(1 / ray->ray_dir_x);
	if(ray->ray_dir_y == 0)
		ray->delta_dist_y = MAX;
	else 
		ray->delta_dist_y = abs(1 / ray->ray_dir_y)
}

void ft_set_step_and_side_dist(t_ray *ray, t_player *player, t_map *map)
{
	if(ray->ray_dir_x = 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - map->map_x) * ray->delta_dist_x; 
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = 
	}
}

void ft_print_ray(t_root *root, double x, double y, int n)
{
	// double value1;
	// double value2;

	(void)n;
	(void)x;
	(void)y;
	(void)root;
	printf("wall: %f, %f\n", x, y);
	//mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[1].img, 0, 0);
	// value1 = (x - root->player->x) * (x - root->player->x);
	// value2 = (y - root->player->y) * (y - root->player->y);
	// root->rays[n].dis_wall = sqrt(value1 + value2);

	
}

void ft_cast_rays(t_root *root)
{
    ft_init_rays(root);

}

void ft_render_map(t_root *root)
{
	int i;
	int j;
	int color;
	t_data map;

	i = -1;
	map.img = mlx_new_image(root->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		if (i < SCREEN_HEIGHT / 2)
			color = CEILING_COLOR;
		else
			color = FLOOR_COLOR;
		while (++j < SCREEN_WIDTH)
            my_mlx_pixel_put(&map, j, i, color);
	}
	root->mlx->map = map;
	ft_cast_rays(root);
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->mlx->map.img, 0, 0);
}