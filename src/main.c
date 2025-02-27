/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/27 17:23:15 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
int **parse_map(char *map, int width, int height)
{
	int fd;
	int i;
	char **storege_line;

	i = 0;
	fd = open(map, O_RDONLY);
	while (storege[i] = get_next_line(fd) != NULL)
	{
		i++;		
	}
}
*/

t_fdf *init_fdf(char *file)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		free(fdf);
		exit(1);
	}
	fdf->zoom = 20;
	fdf->shift_x = 20;
	fdf->shift_y = 20;
	init_window(file, fdf);
	fdf->maps = read_map(file, t_fdf *fdf);
	return (fdf);
}

t_fdf *init_map(void)
{
	t_fdf *map;
	map = malloc(sizeof(t_fdf));
	if (map == NULL)
	{
		free(map);
		exit(1);
	}
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->rows = 0;
	map->cols = 0;
	return (map);
}

void init_window(char *file, t_fdf *fdf)
{
	
	fdf->mlx = mlx_init();
	fdf->maps = read_map(map_name);
	if (!fdf->mlx)
	{
		free(fdf->mlx);
		exit(1);
	}
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
	{
		free(fdf->win);
		exit(1);
	}
	mlx_key_hook(fdf->win, close_window_ESC, NULL);
	mlx_hook(fdf->win, 17, 0, close_window_X, NULL);
	mlx_loop(fdf->mlx);
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
	fdf = init_fdf(argv[1]);
	return (0);
}
