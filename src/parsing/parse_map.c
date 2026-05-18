/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:16:04 by gabch             #+#    #+#             */
/*   Updated: 2026/05/18 19:37:42 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a recheck
int	get_max_width(char **map, int size_y)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	if (!map || !*map)
		clean_exit(NULL, ft_error("check null", MALLOC_ERR), NULL);
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
			clean_exit(data, ft_error("malloc", PARSING_NORMALIZE_MAP), NULL);
		ft_strlcpy(new_line, data->map[i], curr_len + 1);
		while (curr_len < max_w)
			new_line[curr_len++] = ' ';
		new_line[max_w] = '\0';
		free(data->map[i]);
		data->map[i] = new_line;
		i++;
	}
}

void	parse_map(t_data *data, int size_map, const char *filename)
{
	char	*line;

	int (i) = 0;
	int (j) = 0;
	int (fd) = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (size_map + 1));
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[j] != '\0' && ft_isspace(line[j]))
			j++;
		if (!ft_strncmp(&line[j], "1", 1))
		{
			data->map[i] = ft_strdup(line);
			ft_check_null(data, data->map[i]);
			if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
				data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
			i++;
		}
		free(line);
		line = get_next_line(fd);
		j = 0;
	}
	data->map[i] = NULL;
	normalize_map(data);
	close(fd);
}
