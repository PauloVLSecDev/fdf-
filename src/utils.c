/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:45:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/14 20:11:39 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_fdf *map)
{
	int i = 0;
	int j = 0;
	
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)	
		{
			printf("%d  ", map->maps[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	close_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->maps)
		free_map(fdf->maps, fdf->rows);
	if (fdf->mlx_ptr)
	{
		//if (fdf->img)
		//	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
	free(fdf);
	exit(0);
}

void	free_map(int **map, int lines)
{
	int i;

	i = 0;
	while (i < lines)
		free(map[i++]);
	free(map);
}














