/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_trimmed_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:56 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/09/16 16:57:49 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char *ft_get_trimmed_line(char *line)
{
	char *tmp;
	char *tmp1;

	tmp = ft_strtrim(line, " ");
	tmp1 = ft_strtrim(tmp, "\t");
	free(tmp);
	return (tmp1);
}