/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/20 17:14:01 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_H(t_fdf *fdf, t_point start, t_point end, int color)
{
	t_point temp;
	if (start.x > end.x)
	{
		temp = start;
		start = end;
		end = temp;
	}
	while (start.x <= end.x)
	{
		put_pixel_to_image(&fdf->img, start.x, start.y, color);
		start.x++;
	}
}

/*
void	draw_V(t_fdf *fdf, t_point start, t_point end, int color)
{
	t_point temp;
	if (start.x > end.x)
	{
		temp = start;
		start = end;
		end = temp;
	}
	while (start.y <= end.y)
	{
		put_pixel_to_image(&fdf->img, start.x, start.y, color);
		start.x++;
	}
}
*/

void	create_img(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, 
	&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	return ;
}

void	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}
void	draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	t_point start;
	t_point end;

	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			start = init_s_points(x, y, fdf->maps[y][x]);
			end = init_s_points(x, y, fdf->maps[y][x + 1]);
			draw_H(fdf, start, end, 0xFFFFFF);
		//	end = init_s_points(x, y, fdf->maps[y + 1][x]);
		//	draw_V(fdf, start, end, 0xFFFFFF);
			x++;
		}
		y++;
	}
	return ;
}

/*
void	draw_braseham(t_fdf *fdf)
{
	int	dy;
	int	dx;
	int	i;
	int	y;

	i = 0;
	dx = fdf->maps[1][1] - fdf->maps[1][0];
	dy = fdf->maps[1] - fdf->maps[0];
	
	while (i < fdf->cols > (dx + 1))
	{
		y = 1;
		//put_pixel_to_image(&fdf->img, fdf->maps[1][i++], *fdf->maps[1], 0xFFFFFF);
		put_pixel_to_image(&fdf->img, i, y, 0xFFFFFF);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win, fdf->img.img, 0, 0);
	return ;
}
*/
