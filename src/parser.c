/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:57:48 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/27 16:21:25 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int **read_map(char *file, t_fdf map) {
{
	int i = 0;
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = init_map();
	while (line = get_next_line(fd) != NULL)
	{
		map->maps[map->rows] = convert_line_to_int(line, t_fdf map);
		map->rows++;
		free(line);
		printf("%d", map->rows);
		printf("%s", linh);
	}
	return (map->maps);
}

int	*convert_line_to_int(char *line t_fdf map)
{
	int cols;
	int i;
	int *number;
	char **split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (NULL);
	while (split_line[i])
		map->cols += cols++:
	numbers = malloc(sizeof(int) * cols);
	i = 0;
	if (split_line[cols] >= '0' && split_line[cols] <= '9' )
	{
		while (i < cols)
		{
			numbers[i] = ft_atoi(split_line[i]);
			i++;
		}
	}
	free_array(split_line);
	return (numbers);
}
