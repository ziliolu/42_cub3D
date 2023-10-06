#include "./includes/cub3D.h"

void    ft_init_colors(t_tinfo *tinfo)
{
    int i;

    i = 0;
    while(i < 3)
    {
        tinfo->floor[i] = -1;
        tinfo->ceil[i] = -1;
        i++;
    }
}

void	ft_init_structs(t_root *root)
{
	t_tinfo 	*tinfo;
	t_map		*map;
	t_mlx		 *mlx;
	t_player	*player;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	create_rays(root);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT	, "Cub3D");
	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
	root->player = player;
    player->n_players = 0;
	root->error_msg = NULL;
    ft_init_colors(root->tinfo);
    memset(&root->tinfo->north, 0, sizeof(t_data));
    memset(&root->tinfo->south, 0, sizeof(t_data));
    memset(&root->tinfo->west, 0, sizeof(t_data));
    memset(&root->tinfo->east, 0, sizeof(t_data));
    root->map->n_col = 0;
    root->map->n_lines = 0;
}

int main(int argc, char **argv)
{
	t_root *root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	if (argc != 2)
		return (ft_panic(root));
	ft_create_map_image(root->mlx);
	if(!ft_initial_validation(argv[1], root))
		return (1);
	ft_create_minimap_images(root->mlx, root->map);
	ft_render_map(root);
	hooks(root);
    //ft_panic(root);
}
