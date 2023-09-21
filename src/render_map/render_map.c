#include "../../includes/cub3D.h"

double ft_degrees_to_radians(double degrees)
{
	double radians;

	radians = degrees * (PI / 180);
	return (radians);
}

void ft_init_rays(t_root *root)
{
	int i;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		root->rays[i].dis_wall = -1;
		root->rays[i].angle = root->player->direction - (ft_degrees_to_radians(FOV)/ 2) + (i * (ft_degrees_to_radians(FOV) / SCREEN_WIDTH));
	}
}

void ft_print_ray(t_root *root, double x, double y, int n)
{
	double value1;
	double value2;

	value1 = (x - root->player->x) * (x - root->player->x);
	value2 = (y - root->player->y) * (y - root->player->y);
	root->rays[n].dis_wall = sqrt(value1 + value2);
}

void ft_cast_rays(t_root *root)
{
	int	i;
	double angle_increment;
	double step_x;
	double step_y;
	double ray_x;
	double ray_y;
	bool is_wall;
	
	i = -1;
	is_wall = false;
	angle_increment = ft_degrees_to_radians(FOV) / SCREEN_WIDTH;
	ft_init_rays(root);
	while (++i < SCREEN_WIDTH)
	{
		ray_x = root->player->x;
		ray_y = root->player->y;
		step_x = cos(root->rays[i].angle) * SPEED;
		step_y = sin(root->rays[i].angle) * SPEED;

		while(!is_wall)
		{
			ray_x += step_x;
            ray_y += step_y;
			if(root->map->map_arr[(int)ray_y][(int)ray_x] == '1')
			{
				is_wall = true;
				ft_print_ray(root, ray_x, ray_y, i);
			}
		}
	}
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