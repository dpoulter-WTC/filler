/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:27:46 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/12 18:37:33 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	best_pos(t_map *map, t_piece *piece)
{
	int y;
	int x;
	int i;
	int min;
	int mini;

	i = 0;
	mini = 0;
	min = map->map_x + 1 + map->map_y + 1;
	while (i < map->pos_num)
	{
		x = 0;
		while (x < map->map_x)
		{
			y = 0;
			while (y < map->map_y)
			{
				if(ft_toupper(map->map[x][y]) == map->en)
				{
					if (min > abs(x - map->pos[i][0]) + abs(y - map->pos[i][1])) 
					{
						min = abs(x - map->pos[i][0]) + abs(y - map->pos[i][1]);
						mini = i;
					}
				}
				y++;
			}
			x++;
		}
		i++;
	}
	ft_putnbr_fd(map->pos[mini][0] , 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(map->pos[mini][1], 1);
	ft_putchar_fd('\n', 1);	
}

