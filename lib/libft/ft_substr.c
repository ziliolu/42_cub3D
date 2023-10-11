/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:23:00 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/10/10 14:34:28 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a substring
** from the string ’s’. The substring begins at index
** ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result_str;

	i = 0;
	if (!s)
		return (NULL);
	if(start > ft_strlen(s))
	{
		result_str = malloc(sizeof(char) * 1);
		if(!result_str)
			return (NULL);
		result_str[0] = '\0';
		return (result_str);
	}
	result_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (NULL);
	while (s[i] && len-- > 0)
		result_str[i++] = s[start++];
	result_str[i] = '\0';
	return (result_str);
}

/* int main()
{
    char *s = "lorem ipsum dolor sit amet";
    unsigned int start = 0;
    size_t len = 5;

    char *substr = (ft_substr("0123456789", 9, 10));
    printf("%s", substr);
} */