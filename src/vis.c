/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:55:57 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/31 14:57:10 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <sys/ioctl.h>

void	print(t_map *map, char *s)
{
	int x;

	x = -1;
	while (s[++x])
	{
		if (map->map_y > 200)
			++x;
		if (ft_toupper(s[x]) == map->en)
		{
			ft_putstr_fd("\033[31m", 2);
			ft_putstr_fd("\u2590", 2);
		}
		else if (ft_toupper(s[x]) == map->me)
		{
			ft_putstr_fd("\033[32m", 2);
			ft_putstr_fd("\u2590", 2);
		}
		else
		{
			ft_putstr_fd("\033[0m", 2);
			ft_putchar_fd(s[x], 2);
		}
	}
}

void	f(char *s, t_map *map, int size)
{
	int y;

	y = 0;
	while (++y < (size - map->map_y) / 2)
		ft_putchar_fd(' ', 2);
	print(map, s);
}

void	vis(t_map *map)
{
	int				i;
	struct ttysize	ts;
	int				size;

	i = -1;
	ioctl(2, TIOCGWINSZ, &ts);
	ft_putstr_fd("\e[1;1H", 2);
	size = map->map_x;
	if (map->map_x > 40)
		size /= 2;
	while (++i < (ts.ts_lines - size) / 2)
		ft_putchar_fd('\n', 2);
	i = -1;
	while (++i < map->map_x)
	{
		if (map->map_x > 40)
			++i;
		f(map->map[i], map, (int)ts.ts_cols);
		ft_putstr_fd("\033[0m\n", 2);
	}
}
