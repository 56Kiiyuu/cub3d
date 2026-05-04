/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:03:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/04 14:22:49 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Check X
// Check Y
int	validate_move(t_data *data, double newX, double newY)
{
	int	moved;
	int	curr_x = (int)data->player->posX;
	int	curr_y = (int)data->player->posY;

	moved = 0;
	if ((int)newX >= 0 && (int)newX < (int)ft_strlen(data->map[curr_y]))
	{
		if (data->map[curr_y][(int)newX] == '0')
			{
				data->player->posX = newX;
				moved = 1;
			}
	}
	if ((int)newY >= 0 && (int)newY < data->map_size_y)
	{
		if (data->map[(int)newY] && curr_x < (int)ft_strlen(data->map[(int)newY]))
		{
			if (data->map[(int)newY][curr_x] == '0')
			{
				data->player->posY = newY;
				moved = 1;
			}
		}
	}
	return (moved);
}
