/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:23:33 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/31 14:46:17 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_set(t_map *m, t_piece *piece, char *ln)
{
	int		i;
	int		j;
	int		row_num;

	i = 0;
	while (ln[i] != ' ')
		i++;
	row_num = ft_atoi(ln);
	j = -1;
	while (ln[++i])
	{
		m->map[row_num][++j] = ln[i];
		if (m->me_x == 0 && ft_toupper(ln[i] == m->me))
		{
			m->me_x = row_num;
			m->me_y = j;
		}
		if (m->en_x == 0 && ft_toupper(ln[i]) == m->en)
		{
			m->en_x = row_num;
			m->en_y = j;
		}
		m->map[row_num][j + 1] = '\0';
	}
}

void	mallocing_map(t_map *map)
{
	int i;

	i = -1;
	map->map = (char **)malloc(sizeof(char *) * map->map_x);
	map->map_old = (char **)malloc(sizeof(char *) * map->map_x);
	while (++i < map->map_x)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->map_y + 1);
		map->map_old[i] = (char *)malloc(sizeof(char) * map->map_y + 1);
	}
}

void	set_size(t_map *map, t_piece *piece, char *line)
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
	}
	map->map_x = ft_atoi(digit);
	j = 0;
	ft_bzero(digit, ft_strlen(line));
	while (ft_isdigit(line[++i - 1]))
		digit[j++] = line[i - 1];
	map->map_y = ft_atoi(digit);
	mallocing_map(map);
	free(digit);
}
