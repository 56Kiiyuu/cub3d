/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:03:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/07 18:12:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Check X
// Check Y
int	is_walkable(t_data *data, int x, int y)
{
	char	c;

	if (y < 0 || y >= data->map_size_y || x < 0 || !data->map[y][x])
		return (0);
	c = data->map[y][x];
	// MANDATORY
	if (c == '0' || ft_strchr("NSEW", c))
		return (1);
	// BONUS FOR DOORS (O == open)
	if (BONUS && c == 'O')
		return (1);
	return (0);
}

int	validate_move(t_data *data, double newX, double newY)
{
	int	moved;

	moved = 0;
	if (is_walkable(data, (int)newX, (int)data->player->posY))
	{
		data->player->posX = newX;
		moved = 1;
	}
	if (is_walkable(data, (int)data->player->posX, (int)newY))
	{
		data->player->posY = newY;
		moved = 1;
	}
	return (moved);
}
