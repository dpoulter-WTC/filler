/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:20:18 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/21 10:20:19 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!s)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(fresh + i) = f(*(s + i));
	return (fresh);
}
