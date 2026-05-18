/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:43:30 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/18 19:14:11 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_data(t_data *data, int x, int y)
{
	if (data->player->direction != '\0')
		clean_exit(data, ft_error("spawn.c", ERR_PARSER_MANY_SPAWN), NULL);
	data->player->pos_x = (double)x + 0.5 ;
	data->player->pos_y = (double)y + 0.5 ;
	data->player->direction = data->map[y][x];
	data->map[y][x] = '0';
}

void	parse_spawn(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player->direction = '\0';
	while (i < data->map_size_y)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] && ft_strchr("NSEW", data->map[i][j]))
				fill_data(data, j, i);
			j++;
		}
		i++;
	}
	if (data->player->direction == '\0')
		clean_exit(data, ft_error("parse_spawn.c", ERR_PARSER_NO_SPAWN), NULL);
}
