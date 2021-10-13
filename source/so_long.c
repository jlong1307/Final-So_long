/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:04:45 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 10:24:24 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_img *map)
{
	int	i;

	i = -1;
	while (++i < map->map_y)
	{
		free(map->ptab[i]);
	}
	if (map->ptab)
		free(map->ptab);
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	ft_free(t_img *img)
{
	int	i;

	i = -1;
	(void)img;
	while (++i < img->map_y)
	{
		free(img->ptab[i]);
	}
	if (img->ptab)
		free(img->ptab);
	if (img)
		free(img);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **av)
{
	t_img	*mlx;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	mlx = malloc(sizeof(t_img));
	if (!mlx)
		free(mlx);
	mlx = check_map(av, mlx);
	build_map(mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, press_key, mlx);
	mlx_hook(mlx->mlx_win, 17, 1l << 17, x_close_win, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
