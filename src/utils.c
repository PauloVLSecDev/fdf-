/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:45:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/28 16:36:56 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->maps)
		free_map(fdf->maps, fdf->rows);
	if (fdf->mlx_ptr)
	{
		if (fdf->win)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win);
		if (fdf->img.img)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
	free(fdf);
	exit(0);
}

void	free_map(int **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
		free(map[i++]);
	free(map);
}

static void	validade_file_name(char *file_name, int fd)
{
	char	*point;

	point = ft_strrchr(file_name, '.');
	if (!point || ft_strncmp(point, ".fdf", ft_strlen(".fdf")) != 0)
		exit_w_code(fd, 42, "format expected: .fdf");
	return ;
}

static int	validade_cols_of_lines(int fd, int flag)
{
	char	*line;
	int		cols_next_line;
	int		previus_line;

	line = get_next_line(fd);
	if (!line)
		exit_w_code(fd, 3, "map is NULL");
	previus_line = count_cols(line);
	while (line)
	{
		cols_next_line = count_cols(line);
		if (previus_line != cols_next_line)
			flag = 1;
		free(line);
		line = get_next_line(fd);
		previus_line = cols_next_line;
	}
	close(fd);
	return (flag);
}

void	validade_all(char *file)
{
	int	fd;
	int	flag;
	int	valid;

	flag = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_w_code(fd, 1, file);
	validade_file_name(file, fd);
	valid = validade_cols_of_lines(fd, flag);
	if (valid == 1)
		exit_w_code(fd, 1, "invalid cols");
	return ;
}
