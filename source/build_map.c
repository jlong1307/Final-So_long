/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:41:18 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 10:11:39 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_inside_map_bis(t_img *mlx, int i, int j)
{
	if (mlx->ptab[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->col.img,
			(j * mlx->multi) + 7, (i * mlx->multi) + 10);
	else if (mlx->ptab[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img,
			(j * mlx->multi), (i * mlx->multi));
		mlx->player.x = j;
		mlx->player.y = i;
	}
}

void	build_inside_map(t_img *mlx)
{
	int		i;
	int		j;

	i = -1;
	init_image(mlx);
	while (++i < mlx->map_y)
	{
		j = -1;
		while (++j < mlx->map_x)
		{
			if (mlx->ptab[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall.img,
					(j * mlx->multi), (i * mlx->multi));
			else if (mlx->ptab[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ground.img,
					j * mlx->multi, i * mlx->multi);
			else if (mlx->ptab[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit.img,
					(j * mlx->multi) + 5, (i * mlx->multi) + 5);
			else
				build_inside_map_bis(mlx, i, j);
		}
	}
}

void	build_map(t_img *mlx)
{
	int	sizex;
	int	sizey;
	int	totalx;
	int	totaly;

	mlx->map_x = mlx->x;
	mlx->map_y = mlx->y;
	init_struct_img(mlx);
	init_screen(mlx);
	mlx_get_screen_size(mlx->mlx, &sizex, &sizey);
	totalx = mlx->map_x * mlx->multi;
	totaly = mlx->map_y * mlx->multi;
	if (totalx > sizex || totaly > sizey)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		printf("Error\nSize of the map is so big!\n");
		ft_error(mlx);
	}
	build_inside_map(mlx);
}
