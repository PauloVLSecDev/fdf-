/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:39:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/28 14:46:27 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**read_map(char *file, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	fdf->rows = count_lines(file);
	fdf->maps = (int **)malloc(sizeof(int *) * fdf->rows);
	if (!fdf->maps)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(fdf->maps);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fdf->maps[i++] = convert_line_to_int(line, fdf);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (fdf->maps);
}

int	count_lines(char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	close (fd);
	return (rows);
}

int	count_cols(char *line)
{
	int		i;
	char	**split_line;
	int		cols;

	split_line = ft_split(line, ' ');
	cols = 0;
	i = 0;
	if (!split_line)
		return (0);
	while (split_line[i])
	{
		if (split_line[i][0] == '\n' && !split_line[i + 1])
		{
			i++;
			continue ;
		}
		cols++;
		i++;
	}
	free_array(split_line);
	return (cols);
}

int	*convert_line_to_int(char *line, t_fdf *map)
{
	int		i;
	int		*number;
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (NULL);
	map->cols = count_cols(line);
	number = malloc(sizeof(int) * map->cols);
	i = 0;
	while (i < map->cols)
	{
		number[i] = ft_atoi(split_line[i]);
		i++;
	}
	free_array(split_line);
	return (number);
}
