/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_identifiers_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:05 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 16:42:01 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	ft_valid_identifier(char *id, char *path, t_root *root)
{
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE")
		|| !ft_strcmp(id, "EA") || !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
	{
		return (ft_add_paths(id, path, root->tinfo, root->mlx));
	}
	return (false);
}

bool	ft_is_text_or_color_filled(char *id, t_tinfo *tinfo)
{
	if (!ft_strcmp(id, "F"))
		return (ft_is_color_complete(tinfo->floor));
	else if (!ft_strcmp(id, "C"))
		return (ft_is_color_complete(tinfo->ceil));
	else if (!ft_strcmp(id, "NO"))
		return (tinfo->north.img);
	else if (!ft_strcmp(id, "SO"))
		return (tinfo->south.img);
	else if (!ft_strcmp(id, "WE"))
		return (tinfo->west.img);
	else if (!ft_strcmp(id, "EA"))
		return (tinfo->east.img);
	return (false);
}
