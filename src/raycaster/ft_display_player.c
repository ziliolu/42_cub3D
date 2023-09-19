#include "../../includes/cub3D.h"

t_data ft_create_square_img(t_mlx *mlx, int color)
{
    t_data img;
    int i;
    int j;

    img.img = mlx_new_image(mlx->mlx, SQUARE_SIZE, SQUARE_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
    while(i < SQUARE_SIZE)
	{
		j = 0;
		while(j < SQUARE_SIZE)
		{
            my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
    }
    return (img);
}

bool is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (true);
    return (false);
}

void ft_render_mini_map(t_root *root)
{
    int i;
    int j;

    i = 0;
    ft_create_map_images(root);
    while(i < root->map->n_lines)
    {
        j = 0;
        while(j < root->map->n_col)
        {
            if(root->map->map_arr[i][j] == '1')
                mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[0].img, j*SQUARE_SIZE, i*SQUARE_SIZE);
            else if (root->map->map_arr[i][j] == '0')
                mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[1].img, j*SQUARE_SIZE, i*SQUARE_SIZE);
            else if (is_player(root->map->map_arr[i][j]))
                mlx_put_image_to_window(root->mlx->mlx, root->mlx->win, root->map->imgs[2].img, j*SQUARE_SIZE, i*SQUARE_SIZE);
            j++;
        }
        i++;
    }
}

void ft_create_map_images(t_root *root)
{
    root->map->imgs[0] = ft_create_square_img(root->mlx, 0x00FF0000);
	root->map->imgs[1] = ft_create_square_img(root->mlx, 0x00FFFFFF);
	root->map->imgs[2] = ft_create_square_img(root->mlx, 0x0008000);
}