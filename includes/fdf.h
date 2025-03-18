/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:03 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/18 19:11:09 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H 

# define WIDTH  1000
# define HEIGHT  800
# define ESC 0xff1b

#include "../library/libft/libft.h"
#include "../library/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win;
	int	**maps;
	int	rows;
	int	cols;
	int	max_z;
	int	min_z;
	int	zoom;
	float	cordenate_x;
	float	cordenate_y;
	float	angle_z;
	float	angle_y;
	float	angle_x;
	float	z_scala;
	int	shift_x;
	int	shift_y;

}	t_fdf;



void	exit_w_code(int fd, int code, void *msg);
int	close_window_ESC(int keycode, t_fdf *fdf);
int	close_window_X(t_fdf *fdf);
int	**read_map(char *file, t_fdf *map);
void	init_window(t_fdf *fdf);
t_fdf	*init_fdf(char *file);
void	init_map(t_fdf *map);
int	*convert_line_to_int(char *line, t_fdf *map);
int	count_cols(char *line);
int	count_lines(char *file);
void	free_map(int **map, int lines);
void	close_fdf(t_fdf *fdf);
void	validade_all(char *file);
void	draw(t_fdf *img);

#endif
