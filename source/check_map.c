/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:47:12 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 09:12:22 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall(t_img *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->ptab[0][x] != '1')
				return (0);
			else if (map->ptab[y][0] != '1')
				return (0);
			else if (map->ptab[y][map->x - 1] != '1')
				return (0);
			else if (map->ptab[map->y - 1][x] != '1')
				return (0);
		}
	}
	return (1);
}

void	check_inside_map(t_img *map)
{
	map->x = ft_strlen(map->ptab[1]);
	if (map->x == map->y)
	{
		printf("Error\nThe map must be rectangular !\n");
		ft_error(map);
	}
	check_caractere(map);
	if (!check_inside_map_bis(map))
	{
		printf("Error\nThe map must be composed of ");
		printf("only 5 possible characters : [1,0,E,P,C]\n");
		ft_error(map);
	}
	if (!check_map_wall(map))
	{
		printf("Error\nThe map must be closed/surrounded by walls!\n");
		ft_error(map);
	}
}

void	get_map(t_img *map, char **av)
{
	char	*line;
	int		i;

	i = 0;
	map->ptab = malloc(sizeof(char *) * map->y);
	if (!map->ptab)
		free(map->ptab);
	map->fd = open(*av, O_RDONLY);
	while (get_next_line(map->fd, &line))
	{
		map->ptab[i] = line;
		i++;
	}
	free(line);
	close(map->fd);
}

t_img	*check_map(char **av, t_img *map)
{
	char	*line;
	int		i;

	i = 0;
	map->y = 0;
	line = NULL;
	av++;
	map->fd = open(*av, O_RDONLY);
	while (get_next_line(map->fd, &line))
	{
		free(line);
		map->y++;
	}
	free(line);
	close(map->fd);
	get_map(map, av);
	check_inside_map(map);
	return (map);
}
