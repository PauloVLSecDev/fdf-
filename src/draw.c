/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/19 16:14:17 by pvitor-l         ###   ########.fr       */
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

void	draw(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (fdf->rows > y)
	{
		x = 0;
		while (fdf->cols > x)	
		{
			if ( x < fdf->cols - 1)
			{
				fdf->cordenate_y = y;
				fdf->cordenate_x = x + 1;
			}
			if ( y < fdf->rows - 1)
			{
				fdf->cordenate_y = y + 1;
				fdf->cordenate_x = x;
			}
		}
	}
	return ;
}

