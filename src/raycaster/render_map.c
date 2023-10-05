#include "../../includes/cub3D.h"

void ft_create_map_image(t_mlx *mlx)
{
	t_data map;

	map.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	mlx->map = map;
}

void ft_render_map(t_root *root)
{
	int i;
	int j;
	int color;

	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		if (i < SCREEN_HEIGHT / 2)
			color = CEILING_COLOR;
		else
			color = FLOOR_COLOR;
		while (++j < SCREEN_WIDTH)
			my_mlx_pixel_put(&root->mlx->map, j, i, color);
	}
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->mlx->map.img, 0, 0);
    ft_cast_rays(root);
    ft_render_mini_map(root->mlx, root->map, root->player, root->rays);
}