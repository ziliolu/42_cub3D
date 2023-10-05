/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:57:00 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/02 12:26:26 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
	
bool ft_is_valid_extension(char *str, char *extension)
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
bool ft_is_color_complete(t_tinfo *tinfo)
{
    int i;

    i = 0;
    while(i < 3)
    {
        if(tinfo->floor[i] == -1 || tinfo->ceil[i] == -1)
            return (false);
        i++;
    }
    return (true);
}

bool ft_istinfo_complete(t_tinfo *tinfo)
{
	if(!tinfo->north.addr || !tinfo->south.addr || !tinfo->west.addr || !tinfo->east.addr || ft_is_color_complete(tinfo))
		return (false);
	return (true);
}

bool ft_is_valid_file(char *str, t_root *root)
{
	int fd;
	char *line;
	char *tmp;
	int copy_map;

	fd = open(str, O_RDONLY);
	copy_map = 0;
	if(open(MAP, O_RDWR) != -1)
		open(MAP, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if(fd == -1)
        return (false);
	line = NULL;
	while((line = get_next_line(fd)))
	{
		tmp = ft_get_trimmed_line(line);
        if(!ft_strcmp(tmp, "\n"))
        {
            printf("quebra de liha\n");
        }
		if((ft_isdigit(tmp[0]) || tmp[0] == ' ') && ft_str_is_map_type(line))
		{
			if(!ft_istinfo_complete(root->tinfo))
			{
				free(tmp);
				free(line);
				root->error_msg = root->errors->tinfo_is_not_complete;
				return (false);
			}
			copy_map = 1;
			ft_add_map_file(line);
		}
		else if(!ft_verify_identifiers(tmp, root) && (copy_map == 1 && ft_strcmp(tmp, "\n")))
		{
			free(line);
			free(tmp);
			root->error_msg = root->errors->not_valid_texture_or_color;
			return (false);
		}
		free(tmp);
		free(line);
	}
	close (fd);
	free(line);
	return (true);
}

//todas as chamadas para error sao dadas aqui, assim evitamos double frees
bool ft_initial_validation(char *str, t_root *root)
{
	if (!ft_is_valid_extension(str, ".cub"))
		return ft_err("invalid extension", root);
	if (!ft_is_valid_file(str, root))
		return ft_err("invalid file", root);
	if(!ft_is_valid_map(root))
		return(ft_err("invalid map", root));
	return (true);
}