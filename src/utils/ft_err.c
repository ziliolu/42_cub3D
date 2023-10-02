/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/02 12:24:40 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool ft_err(char *str, t_root *root)
{
	if(root->error_msg)
		printf("Error: %s: %s\n", str, root->error_msg);
	else 
		printf("Error: %s\n", str);
	ft_panic(root);
	return (false);
}