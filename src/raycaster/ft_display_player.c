#include "../../includes/cub3D.h"

t_data ft_create_square_img(t_mlx *mlx, int color, int size)
{
	t_data img;
	int i;
	int j;

	img.img = mlx_new_image(mlx->mlx, size, size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = -1;
	while(++i < size)
	{
		j = -1;
		while(++j < size)
			my_mlx_pixel_put(&img, i, j, color);
	}
	return (img);
}

void ft_render_mini_map(t_mlx *mlx, t_map *map, t_player *player, t_ray *rays)
{
	int i;
	int j;

	i = -1;
	while(++i < map->n_lines)
	{
		j = -1;
		while(++j < map->n_col)
		{
			if(map->map_arr[i][j] == '1' || map->map_arr[i][j] == '-')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->imgs[0].img, j*SQUARE_SIZE, i*SQUARE_SIZE);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->imgs[1].img, j*SQUARE_SIZE, i*SQUARE_SIZE);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->imgs[2].img, (player->x - 0.25)*SQUARE_SIZE, (player->y - 0.25)*SQUARE_SIZE);
	print_rays(mlx, rays, player);
}

void ft_create_minimap_images(t_mlx *mlx, t_map *map)
{
	map->imgs[0] = ft_create_square_img(mlx, 0x00FF0000, SQUARE_SIZE);
	map->imgs[1] = ft_create_square_img(mlx, 0x00FFFFFF, SQUARE_SIZE);
	map->imgs[2] = ft_create_square_img(mlx, 0x0008000, SQUARE_SIZE / 2);
}