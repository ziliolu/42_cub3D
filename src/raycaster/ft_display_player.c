#include "../../includes/cub3D.h"

t_data ft_create_square_img(t_mlx *mlx, int color)
{
    t_data img;
    int i;
    int j;

    img.img = mlx_new_image(mlx->mlx, 64, 64);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
    while(i < 64)
	{
		j = 0;
		while(j < 64)
		{
            my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
    }
    return (img);
}

void ft_render_mini_map(t_root *root)
{
    int i;
    int j;

    i = 0;
    while(i < root->map->n_lines)
    {
        j = 0;
        while(j < root->map->n_col)
        {
            if(root->map->map_arr[i][j] == '1')
	            mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[0].img, i, j);
            else if (root->map->map_arr[i][j] == '0')
	            mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[1].img, i, j);
            else if(root->map->map_arr[i][j] == '-')
	            mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[2].img, i, j);
            j++;
        }
        i++;
    }
}

void ft_create_map_images(t_root *root)
{
    root->map->imgs[0] = ft_create_square_img(root->mlx, 0x00FF0000);
	root->map->imgs[1] = ft_create_square_img(root->mlx, 0x00FFFFFF);
	root->map->imgs[2] = ft_create_square_img(root->mlx, 0x00000000);
}