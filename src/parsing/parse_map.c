/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:16:04 by gabch             #+#    #+#             */
/*   Updated: 2026/05/13 17:17:10 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	parse_map(t_data *data, int size_map, const char *filename)
{
	int		fd;
	char	*line;

	int (i) = 0;
	int (j) = 0;
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * size_map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[j] != '\0' && ft_isspace(line[j]))
			j++;
		if (!ft_strncmp(&line[j], "1", 1))
		{
			data->map[i] = ft_strdup(line);
			if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
				data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
			i++;
		}
		free(line);
		line = get_next_line(fd);
		j = 0;
	}
}
