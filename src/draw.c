/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/24 15:31:59 by pvitor-l         ###   ########.fr       */
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

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

static void	draw_smaller45(t_fdf *fdf, t_point p0, t_point p1, int color)
{
	int		d;
	int		yi;

	fdf->dx = p1.x - p0.x;
	fdf->dy = p1.y - p0.y;
	yi = 1;
	if (fdf->dy < 0)
	{
		yi = -1;
		fdf->dy = -fdf->dy;
    }
  	d = 2 * fdf->dy - fdf->dx;
	while (p0.x <= p1.x)
	{
		put_pixel_to_image(&fdf->img, p0.x, p0.y, color);
		if (d > 0)
    	{
      		p0.y += yi;
      		d += 2 * (fdf->dy - fdf->dx);
    	}
    	else 
      		d += 2 * fdf->dy;
    	p0.x++;
	}
	return ;
}

static void	draw_bigger45(t_fdf *fdf, t_point p0, t_point p1, int color)
{
	int		d;
	int		xi;

	fdf->dx = p1.x - p0.x;
	fdf->dy = p1.y - p0.y;
	xi = 1;
	if (fdf->dx < 0)
	{
		xi = -1;
		fdf->dx = -fdf->dx;
    }
  	d = 2 * fdf->dx - fdf->dy;
	while (p0.y <= p1.y)
	{
		put_pixel_to_image(&fdf->img, p0.x, p0.y, color);
		if (d > 0)
    	{
      		p0.x += xi;
      		d += 2 * (fdf->dx - fdf->dy);
    	}
    	else 
      		d += 2 * fdf->dx;
    	p0.y++;
	}
	return ;
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
				init_s_points(x + 1, y, fdf->maps[y][x + 1], fdf), 0xFFFFFF);
			}
			if (y < fdf->rows -1)
			{
				draw_bresenham(fdf, init_s_points(x, y, fdf->maps[y][x], fdf),
				init_s_points(x, y + 1, fdf->maps[y + 1][x], fdf), 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
	return ;
}
