#include "../../includes/cub3D.h"

int	ft_get_pixel(t_data img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void ft_init_draw_variables(t_root *root, t_ray *ray)
{
    ray->line_height = (int)SCREEN_HEIGHT / ray->per_wall_dist;
    ray->draw_start = (ray->line_height * -1) / 2 + SCREEN_HEIGHT / 2;
    ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
    if(ray->draw_start < 0)
        ray->draw_start = 0;
    if(ray->draw_end >= SCREEN_HEIGHT)
        ray->draw_end = SCREEN_HEIGHT - 1;
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
    ray->tex_step = 1.0 * TEX_HEIGHT / ray->line_height;
    ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * ray->tex_step;
}

void ft_draw(t_ray *ray, t_root *root, int i)
{
    ft_init_draw_variables(root, ray);
    while(ray->draw_start < ray->draw_end)
    {
        root->tinfo->texY = (int)ray->tex_pos & (TEX_HEIGHT - 1);
        ray->tex_pos += ray->tex_step;
        ray->color = ft_get_pixel(ray->xpm_img, root->tinfo->texX, root->tinfo->texY);
        my_mlx_pixel_put(&root->mlx->map, i, ray->draw_start, ray->color);
        ray->draw_start++;
    }
}

