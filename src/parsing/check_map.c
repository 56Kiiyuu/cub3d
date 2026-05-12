/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:44:58 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/12 15:40:52 by kevlim           ###   ########.fr       */
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
	int	has_door;

	i = 0;
	has_door = 0;
	while (i < data->map_size_y)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'D')
				has_door = 1;
			if (data->map[i][j] == '0' || (BONUS && data->map[i][j] == 'D'))
			{
				if (!check_left(data, j, i) || !check_right(data, j, i)
					|| !check_up(data, j, i) || !check_down(data, j, i))
					return (exit(ft_error("check_map.c", PARSING_WRONG_MAP)));
			}
			j++;
		}
		i++;
	}
	if (BONUS && has_door && !data->params.do_path)
		return (exit(ft_error("check_map.c", PARSING_NO_TEX_DOORS)));
}
