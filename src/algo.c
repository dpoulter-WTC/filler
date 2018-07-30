/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:27:46 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/30 14:35:42 by dpoulter         ###   ########.fr       */
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

void	closest_side(t_map *map, t_piece *piece, int j)
{
	int i;
	int min;
	int mini;

	i = -1;
	mini = 0;
	min = map->map_x + 1 + map->map_y + 1;
	while (++i < map->pos_num)
	{
		if (map->placed == -1)
		{
		if (min > ab(0 - map->pos[i][2]) + ab(j - map->pos[i][3]))
		{
			min = ab(0 - map->pos[i][2]) + ab(j - map->pos[i][3]);
			mini = i;
		}
		}else
		{
		if (min > ab(map->map_x + 2 - map->pos[i][2]) + ab(0 - map->pos[i][3]))
		{
			min = ab(map->map_x + 2 - map->pos[i][2]) + ab(0 - map->pos[i][3]);
			mini = i;
		}
		}
	}
	place(map, mini);
	map->placed *= -1;
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

void	best_pos(t_map *m, t_piece *piece)
{
	int x;
	int i;
	int y;
	int on_top;
	int	found;

	on_top = -1;
	i = -1;
	x = -1;
	found = 0;
	m->placed = 1;
	while (++x < m->map_x)
	{
		y = -1;
		while (++y < m->map_y)
		{
			if (ft_toupper(m->map[x][y]) == m->me && on_top == -1)
				on_top = 0;
			if (ft_toupper(m->map[x][y]) == m->en && on_top == -1 && m->map_x > 40)
				on_top = 2;
			if (m->map[x][0] == m->me || m->map[x][1] == m->me)
				found = 2;
		}
	}
	if (m->map_x < 40 && m->player == 2 && found == 0 && m->map_x > 20)
		closest_side(m, piece, m->map_y);
	else if (found == 2)
	{
		m->placed = -1;
		closest_side(m, piece, 0);
	}
	else if (m->map_x < 20 && m->player == 2 && found == 0)
	{
		m->placed = -1;
		closest_side(m, piece, m->map_y);
	}
	else
		closest(m, piece, on_top);
	free(m->pos);
}
