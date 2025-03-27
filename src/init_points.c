/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:39 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/27 17:31:42 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	init_s_points(int x, int y, int z, t_fdf *fdf)
{
	float	iso_x;
	float	iso_y;
	float	normalize_z;
	t_point p;
	
	z = fmax(fdf->min_z, fmin(z, fdf->max_z));
	normalize_z = (float)(z - fdf->min_z) / fmax(1, fdf->max_z - fdf->min_z);
	set_isos(fdf);
	iso_x = (x - y) * fdf->zoom * cos(M_PI / 6);
	iso_y = (x + y) * fdf->zoom * sin(M_PI / 6) - (normalize_z * fdf->z_scale * 0.5);
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
	if (fdf->z_range == 0)
		fdf->z_range = 1;
	scale_x = (WIDTH * margin) / (fdf->cols + fdf->rows) / cos(M_PI / 6); 
	scale_y = (HEIGHT * margin) / (fdf->cols + fdf->rows) / sin(M_PI / 6) + fdf->z_range;

	fdf->zoom = fmin(scale_x, scale_y);
	fdf->z_scale = fmin(fdf->z_scale, HEIGHT * 0.5f);
}
