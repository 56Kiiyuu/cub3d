/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:43:30 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/05 11:02:02 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	fill_data(t_data *data, int x, int y)
{
	if (data->player->direction != '\0')
		exit(ft_error("parse_spawn.c", ERR_PARSER_MANY_SPAWN));
	data->player->posX = (double)x + 0.5 ;
	data->player->posY = (double)y + 0.5 ;
	data->player->direction = data->map[y][x];
	data->map[y][x] = '0';
}

void	parse_spawn(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->player->direction = '\0';
	while (i < data->map_size_y)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N')
				fill_data(data, j, i);
			else if (data->map[i][j] == 'W')
				fill_data(data, j, i);
			else if (data->map[i][j] == 'E')
				fill_data(data, j, i);
			else if (data->map[i][j] == 'S')
				fill_data(data, j, i);
			j++;
		}
		i++;
		j = 0;
	}
	if (data->player->direction == '\0')
		exit(ft_error("parse_spawn.c", ERR_PARSER_NO_SPAWN));
}
