/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:39:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/15 14:57:01 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int **read_map(char *file, t_fdf *map)
{
	int		i;
	int		fd;
	char		*line;

	map->rows = count_lines(file);
	if (map->rows <= 0)
		return (NULL);
	map->maps = malloc(sizeof(int *) * map->rows);
	if (!map->maps)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map->maps);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->maps[i] = convert_line_to_int(line, map);
		i++;
		free(line);
	}
	print_map(map);
	close(fd);
	return (map->maps);
}
int	count_lines(char *file)
{
	int	fd;
	int	rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		rows++;
		free(line);
	}
	close (fd);
	return (rows);
}
int	count_cols(char *line)
{
	int i;
	char **split_line;
	int cols;

	split_line = ft_split(line, ' ');
	i = 0;
	cols = 0;
	if (!split_line)
		return (0);
	while (split_line[i])
	{
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
	char		**split_line;

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
