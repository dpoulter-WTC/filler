/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:23:33 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/16 12:36:06 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_set(t_map *map, t_piece *piece, char *line)
{
	int		i;
	int		j;
	int		row_num;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	row_num = ft_atoi(line);
	j = -1;
	while (line[i])
	{
		map->map[row_num][++j] = line[i];
		if (map->me_x == 0)
			if (ft_toupper(line[i]) == map->me)
			{
				map->me_x = row_num;
				map->me_y = j;
			}
		if (map->en_x == 0)
			if (ft_toupper(line[i]) == map->en)
			{
				map->en_x = row_num;
				map->en_y = j;
			}
		map->map[row_num][j + 1] = '\0';
		i++;
	}
	j = -1;
}

void	mallocing_map(t_map *map)
{
	int i;

	i = -1;
	map->map = (char **)malloc(sizeof(char *) * map->map_x);
	while (++i < map->map_x)
		map->map[i] = (char *)malloc(sizeof(char) * map->map_y + 1);
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
