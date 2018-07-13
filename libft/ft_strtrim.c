/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:25:06 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/24 09:34:06 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	while (*s && IS_SPACE(*s))
		s++;
	len = ft_strlen(s) == 0 ? 0 : ft_strlen(s) - 1;
	if (len > 0)
	{
		while (IS_SPACE(s[len]))
			len--;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (len--)
		str[i++] = *s++;
	return (str);
}
