/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/30 15:10:17 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

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
	map->z_scale = 350;
	map->zoom = 1;
	map->isoset_x = 0;
	map->isoset_y = 0;
	map->shift_x = 20;
	map->shift_y = 20;
	map->maps = NULL;
	return ;
}

void	init_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		exit(1);
	fdf->win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
		exit(1);
	create_img(fdf);
	return ;
}

static void	check_args(int ac, char **argv)
{
	if (ac != 2)
		exit_w_code(1, 1, "format is: ./fdf map_name.fdf");
	if (!argv || **argv == '\0')
		exit_w_code(0, 1, "argv invalid");
	return ;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	check_args(argc, argv);
	validade_all(argv[1]);
	fdf = init_fdf(argv[1]);
	calculate_steps(fdf);
	draw_grid(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win, fdf->img.img, 0, 0);
	mlx_key_hook(fdf->win, close_window_esc, fdf);
	mlx_hook(fdf->win, 17, 0, close_window_x, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
