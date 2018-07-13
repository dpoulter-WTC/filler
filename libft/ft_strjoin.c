/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:07:00 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/24 09:08:38 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = ft_strnew(s1len + s2len);
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1len)
		*(newstr + i) = *(s1 + i);
	while (++j < s2len)
		*(newstr + i++) = *(s2 + j);
	return (newstr);
}
