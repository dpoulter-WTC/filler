/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:27:46 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/14 01:42:31 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	freeing(t_map *map, t_piece *piece)
{
	int i;

	i = 0;
	while (i < map->map_x)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	i = 0;
	while (i < piece->piece_x)
	{
		free(piece->piece[i]);
		i++;
	}
	free(piece->piece);
}

void	place(t_map *map, int mini)
{
	ft_putnbr_fd(map->pos[mini][0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(map->pos[mini][1], 1);
	ft_putchar_fd('\n', 1);
}

void	best_pos_bottom(t_map *map, t_piece *piece)
{
	int y;
	int x;
	int i;
	int min;
	int mini;


	i = -1;
	mini = 0;
	min = map->map_x + 1 + map->map_y + 1;
	while (++i < map->pos_num)
	{
		x = map->map_x - 1;
		while (--x > map->map_x)
		{
			y = map->map_y - 1;
			while (--y > map->map_y)
				if (ft_toupper(map->map[x][y]) == map->en)
					if (min > abs(x + piece->piece_x - map->pos[i][0]) + abs(y + piece->piece_y - map->pos[i][1]))
					{
						min = abs(x + piece->piece_x - map->pos[i][0]) + abs(y + piece->piece_y - map->pos[i][1]);
						//min = abs(x - map->pos[i][0]) + abs(y - map->pos[i][1]);
						mini = i;
					}
		}
	}
	place(map, mini);
}

void	best_pos(t_map *map, t_piece *piece)
{
	int y;
	int x;
	int i;
	int min;
	int mini;

	i = -1;
	mini = 0;
	min = map->map_x + 1 + map->map_y + 1;
	if (map->map[0][0] != map->en || map->map[0][0] !=map->me)
		place(map, 0);
	else
	{
		while (++i < map->pos_num)
		{
			x = -1;
			while (++x < map->map_x)
			{
				y = -1;
				while (++y < map->map_y)
					if (ft_toupper(map->map[x][y]) == map->en)
					{
						if (min > abs(x - map->pos[i][0]) + abs(y - map->pos[i][1]))
						{
							min = abs(x - map->pos[i][0]) + abs(y - map->pos[i][1]);
							mini = i;
						}
					}
			}
		}
		place(map, mini);
	}
}
