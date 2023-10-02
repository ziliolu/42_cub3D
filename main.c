#include "./includes/cub3D.h"

void	ft_init_structs(t_root *root)
{
	t_tinfo 	*tinfo;
	t_map		*map;
	t_mlx		 *mlx;
	t_player	*player;
	t_ray		*ray;
	t_errors 	*errors;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	ray = malloc(sizeof(t_ray));
	errors = malloc(sizeof(t_errors));

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT	, "Cub3D");
	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
	root->player = player;
	root->ray = ray;
	root->errors = errors; 
	root->error_msg = NULL;
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
    ft_render_map_background(root);
	ft_cast_rays(root);
    ft_render_mini_map(root->mlx, root->map);
	mlx_loop(root->mlx->mlx);
	ft_print_info(root);
}
