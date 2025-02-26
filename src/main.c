/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/26 16:13:33 by pvitor-l         ###   ########.fr       */
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
**/
/*
int **read_map(char *file)
{
	int fd;
	t_fdf *angle;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while(line = get_next_line(fd) != NULL)
	{
		fdf.map = ft_split(line, ' ');
		while (fdf.map[fdf.cols])
			fdf.cols++; 
	}
	return (fdf.map);
}
*/
int 	main (int ac, char **av)
{
	t_fdf *fdf;

	//read_map(av[1]);
	(void)av;
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	if (ac == 2)
	{
		if (!fdf->mlx)
			return (1);
		fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
		if (!fdf->win)
			return (1);
		mlx_key_hook(fdf->win, close_window_ESC, NULL);
		mlx_hook(fdf->win, 17, 0, close_window_X, NULL);
		mlx_loop(fdf->mlx);
		return (0);
	}
}
