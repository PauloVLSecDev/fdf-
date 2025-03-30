/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:39 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/30 15:14:24 by pvitor-l         ###   ########.fr       */
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

t_point	init_p(int x, int y, int z, t_fdf *fdf)
{
	float	iso_x;
	float	iso_y;
	float	normalize_z;
	t_point	p;

	z = fmax(fdf->min_z, fmin(z, fdf->max_z));
	normalize_z = (float)(z - fdf->min_z) / fmax(1, fdf->max_z - fdf->min_z);
	set_isos(fdf);
	iso_x = (x - y) * fdf->zoom * cos(M_PI / 6);
	iso_y = (x + y) * fdf->zoom * sin(M_PI / 6)
		- (normalize_z * (fdf->z_scale * 0.5));
	p.x = (iso_x + fdf->isoset_x);
	p.y = (iso_y + fdf->isoset_y);
	return (p);
}

void	calculate_steps(t_fdf *fdf)
{
	float	margin;
	float	scale_x;
	float	scale_y;

	margin = 0.9f;
	is_range_z(fdf);
	fdf->z_range = fmax(1, fdf->max_z - fdf->min_z);
	scale_x = (WIDTH * margin) / (fdf->cols + fdf->rows) / cos(M_PI / 6);
	scale_y = (HEIGHT * margin) / (fdf->cols + fdf->rows) / sin(M_PI / 6);
	fdf->zoom = fmin(scale_x, scale_y);
	fdf->z_scale = fmin(fmax(10, HEIGHT / 8), HEIGHT / 2);
}
