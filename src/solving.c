/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:44:19 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/12 19:13:53 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		legal(t_map *map, t_piece *piece, int x, int y)
{
	int i;
	int j;
	int placed;

	placed = 0;
	i = 0;
	while (i < piece->piece_x)
	{
		j = 0;
		while (j < piece->piece_y)
		{
			if(piece->piece[i][j] == '*' && (x + i >= map->map_x || y + j >= map->map_y))
				return (0);
			if (piece->piece[i][j] == '*' && ft_toupper(map->map[x + i][y + j]) == map->me)
				placed++;
			if(piece->piece[i][j] == '*' && ft_toupper(map->map[x + i][y + j]) == map->en)
				return (0);
			j++;
		}
		i++;
	}
	if (placed == 1)
		return (1);
	return (0);
}

int		malloc_place(t_map *map, t_piece *piece)
{
	int placed;
	int x;
	int y;
	int i;
	int j;

	x = 0;
	placed = 0;
	map->pos_num = 0;
	while (x < map->map_x)
	{
		y = 0;
		while(y < map->map_y)
		{
			if(legal(map, piece, x, y))
				map->pos_num++;
			y++;
		}
		x++;
	}
	if(malloc_place_2(map, piece))
		return (1);
	return (0);
}

int		malloc_place_2(t_map *map, t_piece *piece)
{
	int i;

	i = -1;
	map->pos = (int **)malloc(sizeof(int *) * map->pos_num);
	while (++i < map->pos_num)
		map->pos[i] = (int *)malloc(sizeof(int) * 2);
	if(placeable(map, piece))
		return (1);
	return (0);
}

int		placeable(t_map *map, t_piece *piece)
{
	int x;
	int y;
	int i;
	int j;
	int	num;

	x = 0;
	num = 0;
	while (x < map->map_x)
	{
		y = 0;
		while(y < map->map_y)
		{
			if(legal(map, piece, x, y))
			{
				map->pos[num][0] = x;
				map->pos[num][1] = y;
				num++;
			}
			y++;
		}
		x++;
	}
	if(map->pos_num == 0)
	{
		ft_putendl_fd("0 0", 1);
		return (1);
	}
	else
	{
		best_pos(map, piece);
	}
	piece->piece_x = 0;
	return (0);
}
