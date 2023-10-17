/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:44 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/13 13:40:17 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		return (printf("Error\n")); 
	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	ft_create_map_image(root->mlx);
	ft_create_minimap_images(root->mlx, root->map);
	if (!ft_initial_validation(argv[1], root))
		return (1);
	ft_render_map(root);
	hooks(root);
	ft_panic(root);
}
