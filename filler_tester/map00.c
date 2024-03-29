/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:24:17 by agiulian          #+#    #+#             */
/*   Updated: 2018/07/13 19:45:58 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfiller.h"

void	map00(t_prm *prm, char player[21])
{
	printf("-------------------------------------------\n");
	printf("|------------------MAP 0------------------|\n");
	printf("-------------------------------------------\n\n");
	if (prm->nb1)
		map00p1(prm, player);
	if (prm->nb2)
		map00p2(prm, player);
}

void	show_status(double percentage)
{
	int x;

	x = 0;
	while(x < percentage)
	{
		fprintf(stderr, "|");
		x++;
	}
	fprintf(stderr, "%.2f%%\r", percentage);
	fflush(stderr);
	system("sleep 1");
}

void	map00p1(t_prm *prm, char player[21])
{
	int		i;
	int		j;
	int		score;
	int		num;
	double	percentage;

	i = 0;
	while (i < prm->player_nb)
	{
		score = 0;
		j = 0;
		num = 0;
		while (j < prm->nb1)
		{
			sprintf(prm->entry, "ruby filler_vm -q -f maps/map00 -p1 \
			players/%s.filler -p2 players/%s.filler > /dev/null", player, \
					prm->player_lst[i]);
			system(prm->entry);
			bzero(prm->entry, 149);
			prm->fd = open("filler.trace", O_RDONLY);
			read(prm->fd, prm->buf, 4096);
			num++;
			percentage = (double)(((double)num / (double)prm->nb1) * 100);
			show_status(percentage);
			if (strstr(prm->buf, player) && !strstr(prm->buf, "Segfault"))
				score++;
			j++;

		}
		print_result(player, prm->player_lst[i], prm->nb1, score);
		i++;
	}
}

void	map00p2(t_prm *prm, char player[21])
{
	int		i;
	int		j;
	int		score;
	int		num;
	double	percentage;

	i = 0;
	while (i < prm->player_nb)
	{
		score = 0;
		j = 0;
		num = 0;
		while (j < prm->nb2)
		{
			sprintf(prm->entry, "ruby filler_vm -q -f maps/map00 -p1 \
			players/%s.filler -p2 players/%s.filler > /dev/null", \
			prm->player_lst[i], player);
			system(prm->entry);
			bzero(prm->entry, 149);
			prm->fd = open("filler.trace", O_RDONLY);
			read(prm->fd, prm->buf, 4096);
			num++;
			percentage = (double)(((double)num / (double)prm->nb2) * 100);
			show_status(percentage);
			if (strstr(prm->buf, player) && !strstr(prm->buf, "Segfault"))
				score++;
			j++;
		}
		print_result(prm->player_lst[i], player, prm->nb2, score);
		i++;
	}
}
