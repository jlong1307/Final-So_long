/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:09:51 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 09:54:32 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_img *mlx, int x, int y)
{
	if (mlx->ptab[y][x] == '1')
	{
		printf("This is a wall!!!\n");
		return (0);
	}
	else if (mlx->ptab[y][x] == 'C')
	{
		mlx->nbr_col = mlx->nbr_col + 1;
		printf("You have %d coins\n", mlx->nbr_col);
		return (1);
	}
	else if (mlx->ptab[y][x] == 'E')
	{
		printf("This is the end GG !\n");
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		printf("You did %d movements and have %d coins\n",
			mlx->mov, mlx->nbr_col);
		ft_free(mlx);
	}
	return (1);
}

int	press_key(int keycode, t_img *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		ft_free(mlx);
	}
	else if (keycode == 13)
		mouv_up(mlx);
	else if (keycode == 0)
		mouv_left(mlx);
	else if (keycode == 1)
		mouv_down(mlx);
	else if (keycode == 2)
		mouv_right(mlx);
	build_inside_map(mlx);
	return (0);
}
