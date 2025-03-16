/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:45:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/16 15:57:27 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	print_map(t_fdf *map)
{
	int i = 0;
	int j = 0;
	
	while (i < map->rows)
	{
		j = 0; while (j < map->cols)	{
			printf("%d  ", map->maps[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/

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
	int	i;

	i = 0;
	while (i < lines)
		free(map[i++]);
	free(map);
}

static void	validade_file_name(char *file_name)
{
	char	*point;

	point = ft_strrchr(file_name, '.');
	if (!point || ft_strncmp(point, ".fdf", ft_strlen(".fdf")) != 0)
	{
		perror("file_name whitout .fdf in end");
		exit(1);
	}
	return ;
}

static int validade_cols_of_lines(int fd)
{
	char	*line;
	int	cols_first_line;
	int	cols;
	
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (1);
	}
	cols_first_line = count_cols(line);	
	printf("%s", line);
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		cols = count_cols(line);
		if (cols_first_line != cols)
		{
			free(line);
			close(fd);
			return (1);
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}


void	validade_all(char *file)
{
	int	fd;
	int	flag;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(" ");
		exit(1);
	}
	validade_file_name(file);
	flag = validade_cols_of_lines(fd);
	if (flag == 1)
	{
		close(fd);
		exit (1);
	}
	return ;
}
