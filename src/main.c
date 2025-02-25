/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/25 18:11:14 by pvitor-l         ###   ########.fr       */
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

int 	main (int ac, char **av)
{
	void *mlx;
	void *win;

	(void)**av;
	mlx = mlx_init();
	if (ac == 2)
	{
		if (!mlx)
			return (1);
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF wireframe");
		if (!win)
			return (1);
		mlx_key_hook(win, close_window_ESC, NULL);
		mlx_hook(win, 17, 0, close_window_X, NULL);
		mlx_loop(mlx);
		return (0);
	}
}
