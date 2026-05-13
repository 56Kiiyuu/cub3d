/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:16:04 by gabch             #+#    #+#             */
/*   Updated: 2026/05/13 13:35:11 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_width(char **map, int size_y)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size_y)
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	normalize_map(t_data *data)
{
	int		i;
	int		max_w;
	char	*new_line;
	int		curr_len;

	i = 0;
	max_w = get_max_width(data->map, data->map_size_y);
	while (i < data->map_size_y)
	{
		curr_len = ft_strlen(data->map[i]);
		new_line = malloc(sizeof(char) * (max_w + 1));
		if (!new_line)
			clean_exit(data, ft_error("malloc", PARSING_NORMALIZE_MAP));
		ft_strlcpy(new_line, data->map[i], curr_len + 1);
		while (curr_len < max_w)
			new_line[curr_len++] = ' ';
		new_line[max_w] = '\0';
		free(data->map[i]);
		data->map[i] = new_line;
		i++;
	}
}

// FIND MAP LINE (if is map content)
int	is_map_line(char *line)
{
	int	i;
	int	has_content;

	i = 0;
	has_content = 0;
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEWDO", line[i])) // CHARACTERS ALLOWED
			return (0);
		if (ft_strchr("01NSEWDO", line[i]))
			has_content = 1;
		i++;
	}
	return (has_content);
}

void	parse_map(t_data *data, int size_map, const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (size_map + 1));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			data->map[i] = line;
			if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
				data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
			printf("%s\n", data->map[i]); // REMOVE FOR NORM
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	data->map_size_y = i;
	normalize_map(data);
	close(fd);
}
