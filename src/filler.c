/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:09:00 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/20 13:36:23 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initiate(t_map *map, t_piece *piece)
{
	map->map = NULL;
	map->map_x = 0;
	map->map_y = 0;
	map->player = 0;
	piece->piece = NULL;
	piece->piece_x = 1;
	piece->piece_y = 0;
	map->pos = NULL;
	map->pos_num = 0;
	map->me = 'a';
	map->en = 'a';
	map->me_x = 0;
	map->me_y = 0;
	map->en_x = 0;
	map->en_y = 0;
}

void	first_time(t_map *map, t_piece *piece)
{
	char	*line;
	char	*digit;
	int		i;

	i = 0;
	digit = ft_strnew(10000);
	while (i < piece->piece_x)
	{
		ft_gnl(0, &line);
		if (ft_strcmp(line, "$$$ exec p1 : [players/dpoulter.filler]") == 0)
			map->me = 'O';
		if (ft_strcmp(line, "$$$ exec p2 : [players/dpoulter.filler]") == 0)
			map->me = 'X';
		if (line[0] == 'P' && line[1] == 'l')
			set_size(map, piece, line);
		if (ft_isdigit(line[0]) == 1)
			map_set(map, piece, line);
		if (line[0] == 'P' && line[1] == 'i')
			set_size_piece(map, piece, line);
		if (line[0] == '*' || line[0] == '.')
			piece_set(map, piece, line, i++);
		ft_strdel(&line);
	}
	free(digit);
	free(line);
}

void	else_time(t_map *map, t_piece *piece)
{
	char	*line;
	char	*digit;
	int		i;

	i = 0;
	line = ft_strnew(10000);
	digit = ft_strnew(10000);
	piece->piece_x = 1;
	while (i < piece->piece_x)
	{
		ft_gnl(0, &line);
		if (line[0] == 'P' && line[1] == 'i')
			set_size_piece(map, piece, line);
		if (ft_isdigit(line[0]) == 1)
			map_set(map, piece, line);
		if ((line[0] == '*' || line[0] == '.') && piece->piece_x != 0)
		{
			piece_set(map, piece, line, i);
			i++;
		}
		ft_strdel(&line);
	}
	free(digit);
	free(line);
}

void	player(t_map *map)
{
	if (map->me == 'O')
	{
		map->player = 1;
		map->en = 'X';
	}
	else
	{
		map->player = 2;
		map->en = 'O';
	}
}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;
	char	*line;
	int		i;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	initiate(map, piece);
	first_time(map, piece);
	player(map);
	malloc_place(map, piece);
	while (1 && map->pos_num != 0)
	{
		map->pos_num = 0;
		i = -1;
		else_time(map, piece);
		vis(map);
		if (malloc_place(map, piece))
		{
			freeing(map, piece);
			break ;
		}
		free_piece(piece);
	}
	free(map);
	free(piece);
	return (0);
}
