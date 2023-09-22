#include "../../includes/cub3D.h"

void ft_print_info(t_root *root)
{
    printf("\n--------- TEXTURES ---------\n\n");
    ft_print_textures(root->tinfo);
    printf("\n -------------- MAP --------------\n\n");
    ft_print_arr(root->map->map_arr);
    printf("\n----------------------------------\n");
    printf("Number of columns: %d\n", root->map->n_col);
    printf("Number of lines: %d\n", root->map->n_lines);
    printf("Player position: %f,%f\n", root->player->x, root->player->y);

}