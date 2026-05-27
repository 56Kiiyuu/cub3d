/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:16:04 by gabch             #+#    #+#             */
/*   Updated: 2026/05/27 17:18:29 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_add_map_line(t_data *data, char *line, int i)
{
	int	len;

	data->map[i] = ft_strdup(line);
	ft_check_null(data, data->map[i]);
	len = ft_strlen(data->map[i]);
	if (len > 0 && data->map[i][len - 1] == '\n')
		data->map[i][len - 1] = '\0';
}

void	parse_map(t_data *data, int size_map, const char *filename)
{
	char	*line;

	int (i) = 0;
	int (j) = 0;
	int (fd) = open(filename, O_RDONLY);
	data->fd = fd;
	data->map = malloc(sizeof(char *) * (size_map + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->tmp_line = line;
		while (line[j] && ft_isspace(line[j]))
			j++;
		if (line[j] == '1')
			ft_add_map_line(data, line, i++);
		free(line);
		data->tmp_line = NULL;
		j = 0;
	}
	data->map[i] = NULL;
	close(fd);
}
