/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:07:52 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/07/31 20:50:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	while (--i >= 0)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (0);
}

/*int main()
{
	printf("FAKE: %s\n", ft_strrchr("hello", 'l'));
	printf("ORIGINAL: %s\n", strrchr("hello", 'l'));
}*/
