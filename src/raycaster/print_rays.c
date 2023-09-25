#include "../../includes/cub3D.h"

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
}

void ft_draw(t_ray *ray, t_mlx *mlx, int i)
{
    int line_height;
    int draw_start;
    int draw_end;

    (void)ray;
    printf("dist: %f\n", ray->per_wall_dist);
    line_height = (int)SCREEN_HEIGHT / ray->per_wall_dist;
    draw_start = (line_height * -1) / 2 + SCREEN_HEIGHT / 2;
    draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if(draw_start < 0)
        draw_start = 0;
    if(draw_end >= SCREEN_HEIGHT)
        draw_end = SCREEN_HEIGHT - 1;
    //my_mlx_pixel_put(&mlx->map, i, draw_start, 0X0008000);
    while(draw_start <= draw_end)
    {
        my_mlx_pixel_put(&mlx->map, i, draw_start, 0X0008000);
        draw_start++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.img, 0, 0);
}