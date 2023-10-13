/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:57:00 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/13 13:41:54 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char *trim(char*);
void get_textures(t_root *root, char *line, int fd)
{
	char	*tmp;
	int		copy_map;

	copy_map = 0;
	while (line)
	{
		root->is_empty_file = false;
		tmp = ft_get_trimmed_line(line);
		if ((tmp[0] == '\n' && copy_map == 1) || ((ft_isdigit(tmp[0])
					|| tmp[0] == ' ') && ft_str_is_map_type(line)))
		{
			if (!ft_istinfo_complete(root->tinfo))
				root->error_msg = INCOMPLETE_TEX_OR_COLOR_ERR;
			copy_map = 1;
			ft_add_map_file(line);
		}
		else if (!ft_verify_identifiers(tmp, root) && ft_strcmp(tmp, "\n"))
			root->error_msg = INVALID_TEX_OR_COLOR_ERR;
		free(tmp);
        free(line);
		line = get_next_line(fd);
	}
	free(line);
}

bool	ft_is_valid_file(char *str, t_root *root)
{
    int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (false);
	root->is_empty_file = true;
	line = get_next_line(fd);
	get_textures(root, line, fd);
	close(fd);
	if (root->is_empty_file || root->error_msg)
		return (false);
	return (true);
}

bool	ft_initial_validation(char *str, t_root *root)
{
	if (!ft_is_valid_extension(str, ".cub"))
		return (ft_err(INVALID_EXTENSION, root));
	if (!ft_is_valid_file(str, root))
		return (ft_err(INVALID_FILE, root));
	if (!ft_is_valid_map(root))
		return (ft_err(INVALID_MAP, root));
	return (true);
}
