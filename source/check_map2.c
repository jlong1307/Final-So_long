/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:08:37 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 08:51:06 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_inside_map_bis(t_img *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->ptab[y][x] != 'P' && map->ptab[y][x] != 'C'
				&& map->ptab[y][x] != 'E' && map->ptab[y][x] != '1'
				&& map->ptab[y][x] != '0')
			{
				return (0);
			}
		}
	}
	return (1);
}

void	check_caractere_bis(t_img *map, int e, int c, int p)
{
	if (p < 1 || p > 1)
	{
		printf("Error\nWe need one player !\n");
		ft_error(map);
	}
	if (e < 1)
	{
		printf("Error\nThere is no EXIT in your map !!\n");
		ft_error(map);
	}
	if (c < 1)
	{
		printf("Error\nThere is no collectible in your map !\n");
		ft_error(map);
	}
}

void	check_caractere(t_img *map)
{
	int	x;
	int	y;
	int	p;
	int	c;
	int	e;

	y = -1;
	p = 0;
	e = 0;
	c = 0;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->ptab[y][x] == 'P')
				p++;
			if (map->ptab[y][x] == 'C')
				c++;
			if (map->ptab[y][x] == 'E')
				e++;
		}
	}
	check_caractere_bis(map, e, c, p);
}
