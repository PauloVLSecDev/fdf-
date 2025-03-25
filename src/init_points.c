/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:39 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/25 18:16:52 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	init_s_points(int x, int y, int z, t_fdf *fdf)
{
	t_point p;
	float	temp_x;
	float	temp_y;

	set_isos(fdf);
	temp_x = (x - y) * fdf->steps * cos(M_PI / 6);
	temp_y = (x + y) * fdf->steps * sin(M_PI / 6) - (z * fdf->z_scale) * fdf->steps;
	p.x = temp_x + fdf->isoset_x;
	p.y = temp_y + fdf->isoset_y;
	p.z = z;

	return (p);
}

void calculate_steps(t_fdf *fdf)
{
	float	margin = 0.9f;
	float	scale_x;
	float	scale_y;

	margin = 0.9f;
	scale_x = (WIDTH * margin) / (fdf->cols + fdf->rows) / cos(M_PI / 6);
	scale_y = (HEIGHT * margin) / (fdf->cols + fdf->rows) / sin(M_PI / 6);

	fdf->steps = fmin(scale_x, scale_y);
}
