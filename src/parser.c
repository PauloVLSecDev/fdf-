/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:57:48 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/03/05 18:02:20 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int **read_map(char *file, t_fdf *map)
{
	int		i;
	int		fd;
	char		*line;

	i = 0;
	printf("tentando abrir aquivo");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	printf("arquivo aberto com sucesso");
	while ((line = get_next_line(fd)) != NULL)
	{
		map->maps[map->rows] = convert_line_to_int(line, map);
		map->rows++;
		printf("%d", map->rows);
		printf("%s", line);
		free(line);
	}
	return (map->maps);
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
