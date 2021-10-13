/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:11:28 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 09:59:22 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_img(t_img *mlx)
{
	mlx->mlx = 0;
	mlx->mlx_win = 0;
	mlx->nbr_col = 0;
	mlx->mov = 0;
}

void	init_image(t_img *mlx)
{
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, "./pictures/wall.XPM",
			&mlx->wall.width, &mlx->wall.height);
	mlx->col.img = mlx_xpm_file_to_image(mlx->mlx, "./pictures/col.XPM",
			&mlx->col.width, &mlx->col.height);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, "./pictures/exit.XPM",
			&mlx->exit.width, &mlx->exit.height);
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx, "./pictures/player.XPM",
			&mlx->player.width, &mlx->player.height);
	if (!mlx->wall.img || !mlx->col.img || !mlx->exit.img || !mlx->player.img)
		ft_error(mlx);
}

void	init_screen(t_img *mlx)
{
	int		multi;
	int		x;
	int		y;

	y = 0;
	multi = 40;
	mlx->multi = multi;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map_x * multi,
			mlx->map_y * multi, "GUCCI GANG");
	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx,
			"./pictures/ground.XPM", &mlx->ground.width,
			&mlx->ground.height);
	while (y < mlx->map_y * multi)
	{
		x = 0;
		while (x < mlx->map_x * multi)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				mlx->ground.img, x, y);
			x += mlx->ground.width - 1;
		}
		y += mlx->ground.height - 1;
	}
}
