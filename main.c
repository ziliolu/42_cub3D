#include "./includes/cub3D.h"

void ft_init_structs(t_root *root)
{
	t_tinfo *tinfo;
	t_map *map;
	t_mlx *mlx;

	tinfo = malloc(sizeof(t_tinfo));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));

	tinfo->north = NULL;
	tinfo->south = NULL;
	tinfo->east = NULL;
	tinfo->west = NULL;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "Cub3D");

	root->tinfo = tinfo;
	root->map = map;
	root->mlx = mlx;
}

int main(int argc, char **argv)
{

	t_root *root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	if (argc != 2)
		return (ft_panic(root));
	if(!ft_initial_validation(argv[1], root))
		return (1);
	ft_render_mini_map(root);
	mlx_loop(root->mlx->mlx);
	ft_print_info(root);
}
