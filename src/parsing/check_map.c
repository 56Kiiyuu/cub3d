/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:44:58 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/14 17:16:36 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

int	check_left(t_data *data, int x, int y)
{
	while (x >= 0)
	{
		if (data->map[y][x] == '1')
			return (1);
		x--;
	}
	return (0);
}

int	check_right(t_data *data, int x, int y)
{
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] == '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_up(t_data *data, int x, int y)
{
	while (y >= 0)
	{
		if (data->map[y][x] == '1')
			return (1);
		y--;
	}
	return (0);
}

int	check_down(t_data *data, int x, int y)
{
	while (y < data->map_size_y)
	{
		if (data->map[y][x] == '1')
			return (1);
		y++;
	}
	return (0);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_size_y)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '0')
			{
				if (!check_left(data, j, i))
					return (exit(ft_error("check_map.c", PARSING_WRONG_MAP)));
				else if (!check_right(data, j, i))
					return (exit(ft_error("check_map.c", PARSING_WRONG_MAP)));
				else if (!check_up(data, j, i))
					return (exit(ft_error("check_map.c", PARSING_WRONG_MAP)));
				else if (!check_down(data, j, i))
					return (exit(ft_error("check_map.c", PARSING_WRONG_MAP)));
			}
			j++;
		}
		j = 0;
		i++;
	}
}
