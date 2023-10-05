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
	t_errors 	*errors;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	errors = malloc(sizeof(t_errors));
	create_rays(root);

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT	, "Cub3D");
	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
	root->player = player;
    root->player->n_players = 0;
	root->errors = errors; 
	root->error_msg = NULL;
    ft_init_colors(root->tinfo);
}

void ft_init_errors_struct(t_errors *errors)
{
    errors->not_valid_texture_or_color = "invalid texture or color";
    errors->tinfo_is_not_complete = "incomplete texture's or color's field";
}

int main(int argc, char **argv)
{
	t_root *root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
    ft_init_errors_struct(root->errors);
	if (argc != 2)
		return (ft_panic(root));
	if(!ft_initial_validation(argv[1], root))
		return (1);
    ft_render_map(root);
    //printf("floor [%d, %d, %d]", root->tinfo->floor[0], root->tinfo->floor[1], root->tinfo->floor[2]);
	hooks(root);
    /* ft_print_info(root); */
}
