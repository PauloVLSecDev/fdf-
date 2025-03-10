/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:39:24 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/05 20:41:07 by pvitor-l         ###   ########.fr       */
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
	map->maps = malloc(sizeof(int *) * (map->rows + 1));
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
		map->maps[i++] = convert_line_to_int(line, map);
		printf("%d", map->rows);
		printf("%s", line);
		free(line);
	}
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
	int		cols;
	int		i;
	int		*number;
	char		**split_line;

	cols = 0;
	i = 0;
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (NULL);
	while (split_line[i])
		map->cols = cols++;
	number = malloc(sizeof(int) * cols);
	i = 0;
	while (i < cols)
	{
		number[i] = ft_atoi(split_line[i]);
		i++;
	}
	free_array(split_line);
	return (number);
}
