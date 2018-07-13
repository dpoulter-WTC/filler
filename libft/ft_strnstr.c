/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:13:03 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/24 12:01:42 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int			i;
	int			j;
	int			k;
	int			found;
	const char	*h;

	h = s1;
	if (!ft_strlen(s2))
		return ((char *)h);
	i = -1;
	found = 1;
	while (*(h + ++i) && i < (int)len)
	{
		j = 0;
		if (*(h + i) == *(s2))
		{
			k = i;
			found = 1;
			while (*(h + k) && *(s2 + j) && j < (int)len && k < (int)len)
				found = ((*(h + k++) == *(s2 + j++)) ? 1 : 0);
			if (found && !*(s2 + j))
				return ((char *)h + i);
		}
	}
	return (NULL);
}
