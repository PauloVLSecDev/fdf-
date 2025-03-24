/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:39 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/24 20:33:26 by pvitor-l         ###   ########.fr       */
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
	temp_y = (x + y) * fdf->steps * sin(M_PI / 6) -z * fdf->steps;

	p.x = temp_x + fdf->isoset_x;
	p.y = temp_y + fdf->isoset_y;
	p.z = z;

	return (p);
}
