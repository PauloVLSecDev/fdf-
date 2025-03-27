/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:51:52 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/26 20:33:28 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	is_range_z(t_fdf *fdf)
{
	int	y;
	int	x;

	fdf->max_z = fdf->maps[0][0];
	fdf->min_z = fdf->maps[0][0];
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)	
		{
			if (fdf->maps[y][x] > fdf->max_z)
				fdf->max_z = fdf->maps[y][x];
			if (fdf->maps[y][x] < fdf->min_z)
				fdf->min_z = fdf->maps[y][x];
			x++;
		}
		y++;
	}
	return ;
}

void	set_isos(t_fdf *fdf)
{
	float pespective_x;
	float pespective_y;
	float center_x;
	float center_y;

	center_x = (fdf->cols - 1) / 2.0f;
	center_y = (fdf->rows - 1) / 2.0f;
	pespective_x = (center_x - center_y) * fdf->zoom * cos(M_PI / 6);
	pespective_y= (center_x + center_y) * fdf->zoom * sin(M_PI / 6);
	
	fdf->isoset_x = (WIDTH / 2) - pespective_x;
	fdf->isoset_y = (HEIGHT / 2) - pespective_y;

	return ;
}
