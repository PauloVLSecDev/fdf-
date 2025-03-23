/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */ 
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:45:03 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/19 16:05:06 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H 

# define WIDTH   600
# define HEIGHT  400
# define ESC 0xff1b
#include "../library/libft/libft.h"
#include "../library/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

typedef struct s_point
{
    int		x;
    int		y;
    int		z;
}		t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;\
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win;
	int		**maps;
	t_image	img;
	int		dx;
	int		dy;
	int		rows;
	int		cols;
	int		zoom;
	float	angle_z;
	float	angle_y;
	float	angle_x;
	float	z_scala;
	int		shift_x;
	int		shift_y;

}	t_fdf;

void	put_pixel_to_image(t_image *img, int x, int y, int color);
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
void	draw_grid(t_fdf *img);
void	create_img(t_fdf *fdf);
void	draw_H(t_fdf *fdf, t_point p0, t_point p1, int color);
t_point	init_s_points(int x, int y, int z);

#endif
