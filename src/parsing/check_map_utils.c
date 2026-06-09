/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:44:58 by gchalmel          #+#    #+#             */
/*   Updated: 2026/06/09 16:47:07 by kevlim           ###   ########.fr       */
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
		if (data->map[y][x] == ' ')
			return (0);
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
		if (data->map[y][x] == ' ')
			return (0);
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
		if (data->map[y][x] == ' ')
			return (0);
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
		if (data->map[y][x] == ' ')
			return (0);
		y++;
	}
	return (0);
}
