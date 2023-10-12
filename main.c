/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:44 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:11:19 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_root	*root;

	root = malloc(sizeof(t_root));
	ft_init_structs(root);
	if (argc != 2)
		return (ft_panic(root));
	ft_create_map_image(root->mlx);
	ft_create_minimap_images(root->mlx, root->map);
	if (!ft_initial_validation(argv[1], root))
		return (1);
	ft_render_map(root);
	hooks(root);
	ft_panic(root);
}
