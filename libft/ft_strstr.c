/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:18:17 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/24 09:12:33 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	int		found;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	found = 0;
	while (*(haystack + ++i) && !found)
	{
		if (*(haystack + i) == *(needle))
		{
			j = 0;
			k = i;
			found = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					found = 0;
			if (found)
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
