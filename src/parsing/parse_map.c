/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:16:04 by gabch             #+#    #+#             */
/*   Updated: 2026/05/28 16:02:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parse_map(t_data *data, int size_map, const char *filename)
{
	data->fd = open(filename, O_RDONLY);
	if (data->fd < 0)
		clean_exit(data, ft_error("parse_map.c", PARSING_NOT_OPEN_FILE), NULL);
	data->map = malloc(sizeof(char *) * (size_map + 1));
	if (!data->map)
		clean_exit(data, ft_error("malloc", MALLOC_ERR), NULL);
	data->is_map = 0;
	data->map_end = 0;
}

void	process_map_line(t_data *data, char *line, int j, int *i)
{
	if (!data->is_map && (line[j] == '1' || line[j] == '0' || line[j] == ' '))
		data->is_map = 1;
	if (data->is_map)
	{
		if (line[j] == '1' || line[j] == '0' || ft_strchr("NSEWDO", line[j]))
		{
			if (data->map_end)
				clean_exit(data, ft_error("parse_map.c",
						ERR_PARSER_BAD_KEYWORD), NULL);
			ft_add_map_line(data, line, (*i)++);
		}
		else if (*i > 0 && (line[j] == '\n' || line[j] == '\0'))
			data->map_end = 1;
	}
}

void	parse_map(t_data *data, int size_map, const char *filename)
{
	char	*line;
	int		j;
	int		i;

	i = 0;
	init_parse_map(data, size_map, filename);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->tmp_line = line;
		j = 0;
		while (line[j] && ft_isspace(line[j]))
			j++;
		if (i < size_map)
			process_map_line(data, line, j, &i);
		free(line);
		data->tmp_line = NULL;
	}
	data->map[i] = NULL;
	data->map_size_y = i;
	normalize_map(data);
	close(data->fd);
	data->fd = -1;
}
