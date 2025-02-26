/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/26 18:46:58 by pvitor-l         ###   ########.fr       */
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

t_fdf init_fdf(void)
{
	t_fdf *fdf;
	fdf = malloc(sizeof(s_fdf))
	if (!fdf)
		return (NULL)
	fdf->zoom = 20;
	fdf->shift_x = 20;
	fdf->shift_y = 20;
}

t_fdf init_map(void)
{
	s_fdf *map;
	map = malloc(sizeof(s_fdf))
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
}
int **read_map(char *file) {
{
	int fd;
	t_fdf *map;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = init_map();
	while(line = get_next_line(fd) != NULL)
	{
		fdf.map = ft_split(line, ' ');
		while (fdf.map[fdf.cols])
			fdf.cols++; 
	}
	return (fdf.map);
}

t_fdf init_winow(char *file)
{
	char *map_name;
	fdf->mlx = mlx_init();
	map_name = file;
	fdf->map = read_map(map_name)
	if (!fdf->mlx)
	{
		free(fdf->mlx);
		return (NULL);
	}
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
		return (NULL);
	mlx_key_hook(fdf->win, close_window_ESC, NULL);
	mlx_hook(fdf->win, 17, 0, close_window_X, NULL);
	mlx_loop(fdf->mlx);
}
int 	main (int argc, char **argv)
{
	check_args(argc, argv);
	init_fdf();
		//read_map(av[1]);
		(void)av;
		fdf = init_window(av[1]);
	return (0);
}
