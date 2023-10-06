#include "../../includes/cub3D.h"

void ft_free_rays(t_ray *rays)
{
    t_ray *tmp;
    while(rays != NULL)
    {
        tmp = rays->next;
        free(rays);
        rays = tmp;
    }
}

void ft_free_double_arr(char **arr)
{
     int i;

     i = 0;
     while(arr[i])
     {
         free(arr[i]);
         i++;
     }
     free(arr);
}

void ft_free_mlx(t_root *root)
{
    mlx_destroy_image(root->mlx->mlx, root->mlx->map.img);
    mlx_destroy_image(root->mlx->mlx, root->tinfo->north.img);
    mlx_destroy_image(root->mlx->mlx, root->tinfo->south.img);
    mlx_destroy_image(root->mlx->mlx, root->tinfo->west.img);
    mlx_destroy_image(root->mlx->mlx, root->tinfo->east.img);
    mlx_destroy_window(root->mlx->mlx, root->mlx->win);
    mlx_destroy_display(root->mlx);
}

int ft_panic(t_root *root)
{
//    free(root->tinfo);
//    free(root->map);
//    free(root->mlx);
//    free(root->player);
    if(root->is_empty_file == true)
        return (1);
    ft_free_rays(root->rays);
//    if(root->map->map_arr)
//        ft_free_double_arr(root->map->map_arr);
    ft_free_mlx(root);
    free(root);
    return (0);
}