/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:27:46 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/31 23:57:27 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place(t_map *map, int mini)
{
	ft_putnbr_fd(map->pos[mini][0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(map->pos[mini][1], 1);
	ft_putchar_fd('\n', 1);
}

void	closest_side(t_map *m, t_piece *piece, int j)
{
	int i;
	int min;
	int mini;

	i = -1;
	mini = 0;
	min = m->map_x + 1 + m->map_y + 1;
	while (++i < m->pos_num)
	{
		if (m->placed == -1)
		{
			if (min > ab(m->map_y - m->pos[i][1]) + ab(0 - m->pos[i][0]))
			{
				min = ab(m->map_y - m->pos[i][1]) + ab(0 - m->pos[i][0]);
				mini = i;
			}
		}
		else if (min > ab(10 - m->pos[i][0]) + ab(0 - m->pos[i][1]))
		{
			min = ab(10 - m->pos[i][0]) + ab(0 - m->pos[i][1]);
			mini = i;
		}
	}
	place(m, mini);
}

void	closest(t_map *m, t_piece *piece, int l)
{
	int x;
	int y;
	int i;
	int min;
	int mini;

	i = -1;
	min = m->map_x + 1 + m->map_y + 1;
	while (++i < m->pos_num)
	{
		x = -1;
		while (++x < m->map_x)
		{
			y = -1;
			while (++y < m->map_y)
				if (ft_toupper(m->map[x][y]) == m->en)
					if (min > ab(x - m->pos[i][l]) + ab(y - m->pos[i][l + 1]))
					{
						min = ab(x - m->pos[i][l]) + ab(y - m->pos[i][l + 1]);
						mini = i;
					}
		}
	}
	place(m, mini);
}

void	algo_decide(t_map *m, int found, t_piece *p, int on_top)
{
	if (m->map_x <= 20 && m->player == 2 && found == 0)
	{
		m->placed = -1;
		closest_side(m, p, 0);
	}
	else if (m->map_x <= 40 && m->player == 2 && found == 0)
	{
		m->placed = 1;
		closest_side(m, p, 0);
	}
	else if (m->map_x < 20 && m->player == 2 && found == 0)
	{
		fprintf(stderr, "3");
		fflush(stderr);
		m->placed = -1;
		closest_side(m, p, m->map_y);
	}
	else
	{
		closest(m, p, on_top);
	}
	free(m->pos);
}

void	best_pos(t_map *m, t_piece *piece, int x)
{
	int i;
	int y;
	int on_top;
	int	found;

	on_top = 0;
	i = -1;
	found = 0;
	m->placed = 1;
	while (++x < m->map_x)
	{
		y = -1;
		while (++y < m->map_y)
		{
			if (m->map[x][y] == m->en && on_top == 0 && m->map_x > 40)
				on_top = 2;
			if (m->map[0][y] == m->me || m->map[1][y] == m->me)
				found = 1;
			if (m->map[x][0] == m->me || m->map[x][1] == m->me)
				found = 1;
		}
	}
	algo_decide(m, found, piece, on_top);
}
