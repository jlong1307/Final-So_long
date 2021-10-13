/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:04:58 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 10:23:44 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
}			t_data;

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	char	**ptab;
	int		fd;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	int		multi;
	t_data	mlx_img;
	t_data	player;
	int		mov;
	t_data	exit;
	t_data	wall;
	t_data	ground;
	t_data	col;
	int		nbr_col;

}			t_img;

int					main(int argc, char **av);
int					get_next_line(int fd, char **line);
int					check_line(char *check);
size_t				ft_strlen(const char *s);
char				*next_line(char *str);
char				*join_str(const char *s1, const char *s2);
char				*line_save(char *save);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
t_img				*check_map(char **av, t_img *map);
void				build_map(t_img *mlx);
void				init_struct_img(t_img *mlx);
void				init_image(t_img *mlx);
void				init_screen(t_img *mlx);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					press_key(int keycode, t_img *mlx);
int					x_close_win(t_img *mlx);
void				mouv_up(t_img *mv);
void				mouv_down(t_img *mv);
void				mouv_left(t_img *mv);
void				mouv_right(t_img *mv);
int					check_wall(t_img *mlx, int x, int y);
void				build_inside_map(t_img *mlx);
void				ft_error(t_img *map);
int					check_inside_map_bis(t_img *map);
void				ft_free(t_img *img);
void				check_caractere(t_img *map);
void				check_caractere_bis(t_img *map, int e, int c, int p);

#endif
