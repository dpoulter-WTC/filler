/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 11:01:23 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/21 18:29:42 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_set(t_map *map, t_piece *piece, char *line, int num)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (line[i])
	{
		piece->piece[num][++j] = line[i];
		piece->piece[num][j + 1] = '\0';
		i++;
	}
}

void	mallocing_piece(t_piece *piece)
{
	int i;

	i = -1;
	piece->piece = (char **)malloc(sizeof(char *) * piece->piece_x + 1);
	i = -1;
	while (++i < piece->piece_x)
		piece->piece[i] = (char *)malloc(sizeof(char) * piece->piece_y + 1);
	i = piece->piece_x;
	piece->piece[i] = (char *)malloc(sizeof(char) * 1);
}

void	set_size_piece(t_map *map, t_piece *piece, char *line)
{
	char	*digit;
	int		i;
	int		j;

	i = -1;
	j = 0;
	digit = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (!ft_isdigit(line[++i]))
		;
	while (ft_isdigit(line[++i - 1]))
	{
		digit[j++] = line[i - 1];
		digit[j] = '\0';
	}
	piece->piece_x = ft_atoi(digit);
	j = 0;
	ft_bzero(digit, ft_strlen(line));
	while (ft_isdigit(line[++i - 1]))
		digit[j++] = line[i - 1];
	piece->piece_y = ft_atoi(digit);
	mallocing_piece(piece);
	free(digit);
}

void	free_piece(t_map *map, t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->piece_x)
	{
		free(piece->piece[i]);
		i++;
	}
	i = -1;
	while (++i < map->map_x)
		map->map_old[i] = ft_strdup(map->map[i]);
	free(piece->piece);
}
