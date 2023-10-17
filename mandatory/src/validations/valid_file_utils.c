/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:51:32 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/13 13:32:43 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	ft_is_valid_extension(char *str, char *extension)
{
	int	ext_len;
	int	str_len;
	int	i;

	ext_len = ft_strlen(extension);
	str_len = ft_strlen(str);
	i = 0;
	while (i++ < str_len - ext_len)
		str++;
	if (ft_strncmp(str, extension, ext_len) == 0)
		return (true);
	return (false);
}

bool	ft_is_color_complete(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_istinfo_complete(t_tinfo *tinfo)
{
	if (!tinfo->north.addr || !tinfo->south.addr || !tinfo->west.addr
		|| !tinfo->east.addr || !ft_is_color_complete(tinfo->floor)
		|| !ft_is_color_complete(tinfo->ceil))
		return (false);
	return (true);
}
