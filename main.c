#include "./includes/cub3D.h"

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