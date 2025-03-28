/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:00:27 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/27 20:39:38 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

static void	draw_smaller45(t_fdf *fdf, t_point p0, t_point p1, int color)
{
	int	d[3];
	int	yi;

	d[0] = p1.x - p0.x;
	d[1] = p1.y - p0.y;
	yi = 1;
	if (d[1] < 0)
	{
		yi = -1;
		d[1] = -d[1];
	}
	d[2] = 2 * d[1] - d[0];
	while (p0.x < p1.x)
	{
		put_pixel_to_image(&fdf->img, p0.x, p0.y, color);
		if (d[2] > 0)
		{
			p0.y += yi;
			d[2] += 2 * (d[1] - d[0]);
		}
		else
			d[2] += 2 * d[1];
		p0.x++;
	}
}

static void	draw_bigger45(t_fdf *fdf, t_point p0, t_point p1, int color)
{
	int	d[3];
	int	xi;

	d[0] = p1.x - p0.x;
	d[1] = p1.y - p0.y;
	xi = 1;
	if (d[0] < 0)
	{
		xi = -1;
		d[0] = -d[0];
	}
	d[2] = 2 * d[0] - d[1];
	while (p0.y < p1.y)
	{
		put_pixel_to_image(&fdf->img, p0.x, p0.y, color);
		if (d[2] > 0)
		{
			p0.x += xi;
			d[2] += 2 * (d[0] - d[1]);
		}
		else
			d[2] += 2 * d[0];
		p0.y++;
	}
}

static void	draw_bresenham(t_fdf *fdf, t_point p0, t_point p1, int color)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_smaller45(fdf, p1, p0, color);
		else
			draw_smaller45(fdf, p0, p1, color);
	}	
	else
	{
		if (p0.y > p1.y)
			draw_bigger45(fdf, p1, p0, color);
		else
			draw_bigger45(fdf, p0, p1, color);
	}
	return ;
}

void	draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			if (x < fdf->cols -1)
			{
				draw_bresenham(fdf, init_s_points(x, y, fdf->maps[y][x], fdf),
				init_s_points(x + 1, y, fdf->maps[y][x + 1], fdf), 0x00dbff);
			}
			if (y < fdf->rows -1)
			{
				draw_bresenham(fdf, init_s_points(x, y, fdf->maps[y][x], fdf),
				init_s_points(x, y + 1, fdf->maps[y + 1][x], fdf), 0x00dbff);
			}
			x++;
		}
		y++;
	}
	return ;
}
