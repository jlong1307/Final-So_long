/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:26:31 by jlong             #+#    #+#             */
/*   Updated: 2021/10/12 17:13:52 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv_up(t_img *mv)
{
	int	x;
	int	y;

	y = mv->player.y - 1;
	x = mv->player.x;
	if (check_wall(mv, x, y))
	{
		mv->ptab[mv->player.y][mv->player.x] = '0';
		mv->ptab[y][x] = 'P';
		mv->mov = mv->mov + 1;
		printf("number of movements : %d\n", mv->mov);
	}
}

void	mouv_down(t_img *mv)
{
	int	x;
	int	y;

	y = mv->player.y + 1;
	x = mv->player.x;
	if (check_wall(mv, x, y))
	{
		mv->ptab[mv->player.y][mv->player.x] = '0';
		mv->ptab[y][x] = 'P';
		mv->mov = mv->mov + 1;
		printf("number of movements : %d\n", mv->mov);
	}
}

void	mouv_left(t_img *mv)
{
	int	x;
	int	y;

	y = mv->player.y;
	x = mv->player.x - 1;
	if (check_wall(mv, x, y))
	{
		mv->ptab[mv->player.y][mv->player.x] = '0';
		mv->ptab[y][x] = 'P';
		mv->mov = mv->mov + 1;
		printf("number of movements : %d\n", mv->mov);
	}
}

void	mouv_right(t_img *mv)
{
	int	x;
	int	y;

	y = mv->player.y;
	x = mv->player.x + 1;
	if (check_wall(mv, x, y))
	{
		mv->ptab[mv->player.y][mv->player.x] = '0';
		mv->ptab[y][x] = 'P';
		mv->mov = mv->mov + 1;
		printf("number of movements : %d\n", mv->mov);
	}
}
