/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:27:46 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/20 08:09:35 by dpoulter         ###   ########.fr       */
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

void	closest_side(t_map *map, t_piece *piece, int side)
{
	int i;
	int min;
	int mini;

	i = -1;
	mini = 0;
	min = map->map_x + 1 + map->map_y + 1;
	while (++i < map->pos_num)
	{
		if (min > ab(side - map->pos[i][0]) + ab(map->me_y - map->pos[i][1]))
		{
			min = ab(side - map->pos[i][0]) + ab(map->me_y - map->pos[i][1]);
			mini = i;
		}
	}
	place(map, mini);
}

void	closest(t_map *map, t_piece *piece, int l)
{
	int x;
	int y;
	int i;
	int min;
	int mini;

	i = -1;
	min = map->map_x + 1 + map->map_y + 1;
	while (++i < map->pos_num)
	{
		x = -1;
		while (++x < map->map_x)
		{
			y = -1;
			while (++y < map->map_y)
				if (ft_toupper(map->map[x][y]) == map->en)
					if (min > ab(x - map->pos[i][l]) + ab(y - map->pos[i][l + 1]))
					{
						min = ab(x - map->pos[i][l]) + ab(y - map->pos[i][l + 1]);
						mini = i;
					}
		}
	}
	place(map, mini);
}

void	best_pos(t_map *map, t_piece *piece)
{
	int x;
	int i;
	int found;
	int y;
	int on_top;

	on_top = -1;
	i = -1;
	found = 0;
	x = -1;
	while (++x < map->map_x && on_top < 0)
	{
		y = -1;
		while (++y < map->map_y && on_top < 0)
		{
			if (ft_toupper(map->map[x][y]) == map->me)
				on_top = 0;
			if (ft_toupper(map->map[x][y]) == map->en)
				on_top = 2;
		}
	}
	closest(map, piece, on_top);
	free(map->pos);
}
