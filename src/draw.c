/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/19 21:01:48 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	create_img(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	return ;
}

void	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}
void	draw_line(t_fdf *fdf)
{
	int	i;
	int	j;
	int	spacing;

	spacing = 50;

	i = 0;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			fdf->x0 = j * spacing + fdf->shift_x;
			fdf->y0 = i * spacing + fdf->shift_y;
			put_pixel_to_image(&fdf->img, fdf->x0, fdf->y0, 0xFFFFFF);
			j++;
		}
		i++;
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
