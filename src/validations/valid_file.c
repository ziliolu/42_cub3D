/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:57:00 by riolivei          #+#    #+#             */
/*   Updated: 2023/10/12 18:01:46 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_textures(t_root *root, char *line, int fd)
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
	close(fd);
}

bool	ft_is_valid_file(char *str, t_root *root)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (open(MAP, O_RDWR) != -1)
		open(MAP, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (false);
	root->is_empty_file = true;
	line = get_next_line(fd);
	get_textures(root, line, fd);
	if (root->is_empty_file || root->error_msg)
		return (false);
	return (true);
}

/* bool	ft_is_valid_file(char *str, t_root *root)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		copy_map;

	fd = open(str, O_RDONLY);
	copy_map = 0;
	if (open(MAP, O_RDWR) != -1)
		open(MAP, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (false);
	line = NULL;
	root->is_empty_file = true;
	while ((line = get_next_line(fd)))
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
	}
	free(line);
	close(fd);
	if (root->is_empty_file || root->error_msg)
		return (false);
	return (true);
} */

bool	ft_initial_validation(char *str, t_root *root)
{
	if (!ft_is_valid_extension(str, ".cub"))
		return (ft_err("invalid extension", root));
	if (!ft_is_valid_file(str, root))
		return (ft_err("invalid file", root));
	if (!ft_is_valid_map(root))
		return (ft_err("invalid map", root));
	return (true);
}
