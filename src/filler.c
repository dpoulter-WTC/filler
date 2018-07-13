/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:09:00 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/11 17:29:37 by dpoulter         ###   ########.fr       */
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
	piece->piece_x = 0;
	piece->piece_y = 0;
	map->pos = NULL;
	map->pos_num = 0;
	map->me = 'a';
	map->en = 'a';
}

void	first_time(t_map *map, t_piece *piece, int f)
{
	char	*line;
	char	*digit;
	int		j;
	int		i;
		
	j = 1;
	i = 0;
	line = ft_strnew(10000);
	digit = ft_strnew(10000);
	piece->piece_x = 1;
	while(i < piece->piece_x)
	{
		ft_gnl(0, &line);
		if (ft_strcmp(line, "$$$ exec p1 : [players/dpoulter.filler]") == 0)
			map->player = 1;
		if (ft_strcmp(line, "$$$ exec p2 : [players/dpoulter.filler]") == 0)
			map->player = 2;
		if (line[0] == 'P' && line[1] == 'l')
			set_size(map, piece, line);
		if (ft_isdigit(line[0]) == 1)
			map_set(map, piece, line, f);
		if (line[0] == 'P' && line[1] == 'i')
			set_size_piece(map, piece, line);
		if (line[0] == '*' || line [0] == '.')
		{
			piece_set(map, piece, line, i, f);
			i++;
		}
		ft_strdel(&line);
	}
	free(digit);
	free(line);
}

void	else_time(t_map *map, t_piece *piece, int f)
{
	char	*line;
	char	*digit;
	int		j;
	int		i;
		
	j = 1;
	i = 0;
	line = ft_strnew(10000);
	digit = ft_strnew(10000);
	piece->piece_x = 1;
	while(i < piece->piece_x)
	{
		ft_gnl(0, &line);
		if (line[0] == 'P' && line[1] == 'i')
			set_size_piece(map, piece, line);
		if (ft_isdigit(line[0]) == 1)
			map_set(map, piece, line, f);
		if ((line[0] == '*' || line [0] == '.') && piece->piece_x != 0)
		{
			piece_set(map, piece, line, i, f);
			i++;
		}
		ft_strdel(&line);
	}
	free(digit);
	free(line);
}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;
	char	*line;
	int i;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	initiate(map, piece);
	int f = open("output.txt", O_RDONLY | O_WRONLY | O_TRUNC);
	first_time(map, piece, f);
	if(map->player == 1)
	{
		map->me = 'O';
		map->en = 'X';
	}
	else
	{
		map->me = 'X';
		map->en = 'O';
	}
	malloc_place(map, piece);
	map->pos_num = 0;
	while(1)
	{
		i = -1;
		/*while(++i < map->pos_num)
		{
			ft_putnbr_fd(map->pos[i][0], f);
			ft_putchar_fd(' ', f);
			ft_putnbr_fd(map->pos[i][1], f);
			ft_putchar_fd('\n', f);
		}*/
		else_time(map, piece, f);
		if(malloc_place(map, piece))
			break;
		map->pos_num = 0;
	}
	return (0);
}
