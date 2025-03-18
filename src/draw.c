/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:58:20 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/18 19:13:15 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


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

