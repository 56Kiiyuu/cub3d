/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:03:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 18:02:58 by gchalmel         ###   ########.fr       */
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
	if (c == '0' || ft_strchr("NSEW", c))
		return (1);
	if (BONUS && c == 'O')
		return (1);
	return (0);
}

int	validate_move(t_data *data, double newX, double newY)
{
	int	moved;

	moved = 0;
	if (is_walkable(data, (int)newX, (int)data->player->pos_y))
	{
		data->player->pos_x = newX;
		moved = 1;
	}
	if (is_walkable(data, (int)data->player->pos_x, (int)newY))
	{
		data->player->pos_y = newY;
		moved = 1;
	}
	return (moved);
}
