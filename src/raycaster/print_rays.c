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

int	ft_get_pixel(t_data img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void ft_draw(t_ray *ray, t_map *map, t_root *root, int i)
{
    int line_height;
    int draw_start;
    int draw_end;
    double step;
    double tex_pos;
    (void)map;
    line_height = (int)SCREEN_HEIGHT / ray->per_wall_dist;
    draw_start = (line_height * -1) / 2 + SCREEN_HEIGHT / 2;
    draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if(draw_start < 0)
        draw_start = 0;
    if(draw_end >= SCREEN_HEIGHT)
        draw_end = SCREEN_HEIGHT - 1;
    if(ray->side == 0)
        root->tinfo->wallX = root->player->y + ray->per_wall_dist * ray->ray_dir_y;
    if(ray->side == 1)
        root->tinfo->wallX = root->player->x + ray->per_wall_dist * ray->ray_dir_x;
    root->tinfo->wallX -= floor(root->tinfo->wallX);
    root->tinfo->texX = (int)(root->tinfo->wallX * (double)(TEX_WIDTH));
    if((ray->side == 0 && ray->ray_dir_x > 0))
        root->tinfo->texX = TEX_WIDTH - root->tinfo->texX - 1;
    if(ray->side == 1 && ray->ray_dir_y < 0)
        root->tinfo->texX = TEX_WIDTH - root->tinfo->texX - 1;
    step = 1.0 * TEX_HEIGHT / line_height;
    tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
    while(draw_start < draw_end)
    {
        root->tinfo->texY = (int)tex_pos & (TEX_HEIGHT - 1);
        tex_pos += step;
        ray->color = ft_get_pixel(ray->xpm_img, root->tinfo->texX, root->tinfo->texY);
        my_mlx_pixel_put(&root->mlx->map, i, draw_start, ray->color);
        draw_start++;
    }
}

