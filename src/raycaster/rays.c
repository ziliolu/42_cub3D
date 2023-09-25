#include "../../includes/cub3D.h"

void ft_init_rays(t_root *root, t_player *player)
{
    player->plane_x = 0;
    player->plane_y = 0.66;
    player->dir_x = -1;
    player->dir_y = 0;
    root->map->map_x = (int)player->x;
    root->map->map_y = (int)player->y;
    root->camera_x = 2 * root->wall_num / SCREEN_WIDTH - 1;
    root->ray->ray_dir_x  = player->dir_x + player->plane_x * root->camera_x;
    root->ray->ray_dir_y = player->dir_y + player->plane_y * root->camera_x;
    //root->map->map_x = (int)(player->x);
    printf("y: %d\n", root->map->map_y);
    root->map->map_y = (int)(player->y);
    root->hit_wall = 0;
}

void ft_cast_rays(t_root *root)
{
    int i;

    i = 0;
    while(i < SCREEN_WIDTH)
    {
        ft_init_rays(root, root->player);
        ft_set_ray_length(root->ray);
        ft_set_step_and_side_dist(root->ray, root->player, root->map);
        ft_dda_algorithm(root, root->ray, root->map);
        ft_draw(root->ray, root->mlx, i);
        i++;
    }
}
