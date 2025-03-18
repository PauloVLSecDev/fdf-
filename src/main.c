/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/17 21:01:31 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf *init_fdf(char *file)
{
	t_fdf *fdf;

	printf("nome do arquivo %s\n", file);
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		free(fdf);
		exit(1);
	}
	init_map(fdf);
	fdf->maps = read_map(file, fdf);
	init_window(fdf);
	return (fdf);
}

void	init_map(t_fdf *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->rows = 0;
	map->cols = 0;
	map->zoom = 20;
	map->shift_x = 20;
	map->shift_y = 20;
	map->maps = NULL;
	return ;
}

void init_window(t_fdf *fdf)
{
	
	t_img	img;
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
	{
		free(fdf->mlx_ptr);
		exit(1);
	}
	fdf->win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
	{
		free(fdf->win);
		exit(1);
	}
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_key_hook(fdf->win, close_window_ESC, fdf);
	mlx_hook(fdf->win, 17, 0, close_window_X, fdf);
	return ;
}

static void check_args(int ac, char **argv)
{
	if (ac != 2)
	{
		perror("format is ./fdf map.fdf");
		exit(0);
	}
	if (!argv || **argv == '\0')
		exit(0);
	return ;
}

int 	main (int argc, char **argv)
{
	t_fdf *fdf;
	check_args(argc, argv);
	validade_all(argv[1]);
	fdf = init_fdf(argv[1]);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
