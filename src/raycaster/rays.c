/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:42:59 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:25:01 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_ray	*last_ray(t_ray *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_ray(t_ray **lst, t_ray *new)
{
	t_ray	*tail;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = last_ray(*lst);
	tail->next = new;
}

t_ray	*new_ray(void)
{
	t_ray	*node;

	node = malloc(sizeof(t_ray));
	if (node == NULL)
		return (NULL);
	node->ray_dir_x = 0;
	node->ray_dir_y = 0;
	node->next = NULL;
	return (node);
}

void	create_rays(t_root *root)
{
	int		i;
	t_ray	*head;
	t_ray	*current;

	i = 0;
	head = new_ray();
	current = head;
	while (++i < SCREEN_WIDTH)
	{
		current = new_ray();
		add_ray(&head, current);
	}
	root->rays = head;
}

void	ft_cast_rays(t_root *root)
{
	int		i;
	t_ray	*head;

	head = root->rays;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		ft_init_ray(root, root->player, i);
		ft_set_ray_length(root->rays);
		ft_set_step_and_side_dist(root->rays, root->player, root->map);
		ft_dda_algorithm(root, root->rays, root->map);
		ft_draw(root->rays, root, i);
		root->rays = root->rays->next;
	}
	mlx_put_image_to_window(root->mlx->mlx, root->mlx->win,
		root->mlx->map.img, 0, 0);
	root->rays = head;
}
