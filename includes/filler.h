/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:12:23 by dpoulter          #+#    #+#             */
/*   Updated: 2018/07/20 13:16:06 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef	struct	s_map
{
	int			map_x;
	int			map_y;
	char		**map;
	int			player;
	int			**pos;
	int			pos_num;
	char		me;
	char		en;
	int			me_x;
	int			me_y;
	int			en_x;
	int			en_y;
}				t_map;

typedef	struct	s_piece
{
	int			piece_x;
	int			piece_y;
	char		**piece;
}				t_piece;

void			map_set(t_map *map, t_piece *piece, char *line);
void			piece_set(t_map *map, t_piece *piece, char *line, int num);
void			set_size(t_map *map, t_piece *piece, char *line);
void			set_size_piece(t_map *map, t_piece *piece, char *line);
void			mallocing_map(t_map *map);
void			mallocing_piece(t_piece *piece);
int				placeable(t_map *map, t_piece *piece);
int				malloc_place(t_map *map, t_piece *piece);
int				malloc_place_2(t_map *map, t_piece *piece);
void			best_pos(t_map *map, t_piece *piece);
void			freeing(t_map *map, t_piece *piece);
void			calc_end(t_map *map, t_piece *piece, int num);
void			free_piece(t_piece *piece);
void			vis(t_map *map);

#endif
