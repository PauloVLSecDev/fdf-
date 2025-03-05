/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/05 18:21:41 by pvitor-l         ###   ########.fr       */
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

	printf("nome do arquivo %s\n", file);
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		free(fdf);
		exit(1);
	}
	fdf->maps = read_map(file, fdf);
	init_map(fdf);
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
	
	fdf->mlx = mlx_init();
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
	printf("%d\n", fdf->zoom);
	printf("%d\n", fdf->shift_x);
	printf("%d\n", fdf->cols);
	return (0);
}
