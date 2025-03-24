/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:51:52 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/24 20:23:25 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	is_max_z(t_fdf *fdf)
{
	int	y;
	int	x;

	fdf->max_z = fdf->maps[0][0];
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)	
		{
			if (fdf->maps[y][x] > fdf->max_z)
				fdf->max_z = fdf->maps[y][x];
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

	is_max_z(fdf);
	pespective_x = (fdf->rows + fdf->cols)* fdf->steps * cos(M_PI / 6);
	pespective_y= (fdf->rows + fdf->cols) * fdf->steps * sin(M_PI / 6)
	- fdf->max_z * fdf->steps;
	
	fdf->isoset_x = (WIDTH - pespective_x) / 2;
	fdf->isoset_y = (HEIGHT - pespective_y) / 2;

	return ;
}
